#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<getopt.h>
#include"operations.h"

const struct option options[] = {
  {"darken", required_argument, 0, 'd'},
  {"brighten", required_argument, 0, 'b'},
  {"negative", no_argument, 0, 'n'},
  {"rotate90", no_argument, 0, 0},
  {"rotate180", no_argument, 0, 0},
  {"rotate270", no_argument, 0, 0},
  {"mirrorh", no_argument, 0, 'h'},
  {"mirrorw", no_argument, 0, 'w'},
  {"binarization", required_argument, 0, 'i'},
  {"middleGrayLevel", required_argument, 0, 'g'},
};

void getArguments(int argc, char *argv[], char **operation, int *p) {
  char short_options[20];
  int short_options_index = -1;
  for (int i = 0; i < 7; i++) {
    if (options[i].val != 0) {
      short_options_index++;
      short_options[short_options_index] = options[i].val;

      if (options[i].has_arg == required_argument) {
        short_options_index++;
        short_options[short_options_index] = ':';
      }
    }
  }

  int opt;
  int option_index = 0;
  while ((opt = getopt_long(argc, argv, short_options, options, &option_index)) != -1) {
    switch (opt) {
      case 'd':
        *operation = "darken";
        *p = atoi(optarg);
        break;
      case 'b':
        *operation = "brighten";
        *p = atoi(optarg);
        break;
      case 'n':
        *operation = "negative";
        break;
      case 'h':
        *operation = "mirrorh";
        break;
      case 'w':
        *operation = "mirrorw";
        break;
      case 'i':
        *operation = "binarization";
        *p = atoi(optarg);
        break;
      case 'g':
        *operation = "middleGrayLevel";
        *p = atoi(optarg);
        break;
      case 0:
        if (strcmp(options[option_index].name, "rotate90") == 0) {
          *operation = "rotate90";
        } else if (strcmp(options[option_index].name, "rotate180") == 0) {
          *operation = "rotate180";
        } else if (strcmp(options[option_index].name, "rotate270") == 0) {
          *operation = "rotate270";
        }
        break;
    }
  }
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
  char * operation = "\0";
  // Parâmetro para as operações darken e brighten
  int p = -1;

  // Recebe os argumentos passados para o programa
  getArguments(argc, argv, &operation, &p);

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
  } else if (strcmp(operation, "mirrorw") == 0) {
    mirrorw(image, rows, columns, maxGray);
  } else if (strcmp(operation, "binarization") == 0) {
    binarization(image, rows, columns, maxGray, p);
  } else if (strcmp(operation, "middleGrayLevel") == 0) {
    middleGrayLevel(image, rows, columns, maxGray, p);
  } else {
    printf("Operação inválida\n");
  }

  fclose(image);

  return 0;
}
