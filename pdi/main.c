#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<getopt.h>
#include"operations.h"

void getArguments(int argc, char *argv[], const struct option *options, const char **operation, int *p) {
  int options_length = 0;
  while (strlen(options[options_length].name) > 1) options_length++;

  char short_options[options_length * 2];
  int short_options_index = -1;
  for (int i = 0; i < options_length; i++) {
    if (options[i].val != 0) {
      short_options_index++;
      short_options[short_options_index] = options[i].val;

      if (options[i].has_arg == required_argument) {
        short_options_index++;
        short_options[short_options_index] = ':';
      }
    }
  }

  short_options[short_options_index + 1] = '\0';

  int optindex = -1;
  int opt = getopt_long(argc, argv, short_options, options, &optindex);

  if (opt == '?') {
    printf("Argumento inválido\n");
    exit(1);
  }

  if (opt == -1) {
    printf("Nenhum argumento passado\n");
    exit(1);
  }

  if (optindex == -1) {
    for (int i = 0; i < options_length; i++) {
      if (options[i].val == opt) {
        optindex = i;
        break;
      }
    }

    if (optindex == -1) {
      printf("Argumento inválido\n");
      exit(1);
    }
  }

  if (optarg != NULL) {
    *p = atoi(optarg);
  }

  *operation = options[optindex].name;
}

void loadInputImage(FILE * image, int *rows, int *columns, int *maxGray) {
  char * imageType = malloc(2 * sizeof(char));
  fscanf(image, "%s", imageType);

  if (strcmp(imageType, "P2") != 0) {
    printf("O arquivo não é do tipo P2\n");
    exit(1);
  }

  fscanf(image, "%d %d", rows, columns);
  fscanf(image, "%d", maxGray);
}

int main(int argc, char *argv[]) {
  // Pode ser: darken, brighten, negative, rotate90, rotate180, rotate270, mirror
  const char *operation = NULL;
  // Parâmetro para as operações darken e brighten
  int p = -1;

  const struct option options[] = {
    {"darken", required_argument, 0, 'd'},
    {"brighten", required_argument, 0, 'b'},
    {"negative", no_argument, 0, 'n'},
    {"rotate90", no_argument, 0, 0},
    {"rotate180", no_argument, 0, 0},
    {"rotate270", no_argument, 0, 0},
    {"mirrorh", no_argument, 0, 'h'},
    {"mirrorv", no_argument, 0, 'v'},
    {"binarization", required_argument, 0, 'i'},
    {"middleGrayLevel", required_argument, 0, 'g'},
    {"highlight", no_argument, 0, 'l'},
    {"highlightWithReduction", no_argument, 0, 'r'}
  };

  // Recebe os argumentos passados para o programa
  getArguments(argc, argv, options, &operation, &p);

  // Imprime os argumentos recebidos
  printf("p: %d\n", p);
  printf("operation: %s\n", operation);

  // Abre a imagem de entrada e carrega as informações necessárias
  int rows, columns;
  int maxGray;

  FILE * image = fopen("input/lena256.pgm", "r");

  if (image == NULL) {
    printf("Erro ao abrir a imagem\n");
    exit(1);
  }

  loadInputImage(image, &rows, &columns, &maxGray);

  // Encontra a operação a ser realizada e chama a função correspondente
  if (strcmp(operation, "darken") == 0) {
    darken(image, rows, columns, maxGray, p);
  } else if (strcmp(operation, "brighten") == 0) {
    brighten(image, rows, columns, maxGray, p);
  } else if (strcmp(operation, "negative") == 0) {
    negative(image, rows, columns, maxGray);
  } else if (strcmp(operation, "rotate90") == 0) {
    rotate90(image, rows, columns, maxGray);
  } else if (strcmp(operation, "rotate180") == 0) {
    rotate180(image, rows, columns, maxGray);
  } else if (strcmp(operation, "rotate270") == 0) {
    rotate270(image, rows, columns, maxGray);
  } else if (strcmp(operation, "mirrorh") == 0) {
    mirrorh(image, rows, columns, maxGray);
  } else if (strcmp(operation, "mirrorv") == 0) {
    mirrorv(image, rows, columns, maxGray);
  } else if (strcmp(operation, "binarization") == 0) {
    binarization(image, rows, columns, maxGray, p);
  } else if (strcmp(operation, "middleGrayLevel") == 0) {
    middleGrayLevel(image, rows, columns, maxGray, p);
  } else if (strcmp(operation, "highlight") == 0) {
    highlight(image, rows, columns, maxGray, 0);
  } else if (strcmp(operation, "highlightWithReduction") == 0) {
    highlight(image, rows, columns, maxGray, 1);
  } else {
    printf("Operação inválida\n");
  }

  fclose(image);

  return 0;
}
