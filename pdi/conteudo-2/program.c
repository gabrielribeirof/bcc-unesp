#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<getopt.h>

void darken(FILE * image, int rows, int columns, int maxGray, int p) {
  FILE * darkenImage = fopen("lena256-escurecido.pgm", "w");
  fprintf(darkenImage, "P2\n%d %d\n%d\n", rows, columns, maxGray);

  int element, result;
  for (int i=0; i<rows; i++) {
    for (int j=0; j<columns; j++) {
      fscanf(image, "%d", &element);
      result = element - p;

      if (result < 0) {
        result = 0;
      }

      fprintf(darkenImage, "%d\n", result);
    }
  }

  fclose(darkenImage);
}

void brighten(FILE * image, int rows, int columns, int maxGray, int p) {
  FILE * lightenImage = fopen("lena256-clareado.pgm", "w");
  fprintf(lightenImage, "P2\n%d %d\n%d\n", rows, columns, maxGray);

  int element, result;
  for (int i=0; i<rows; i++) {
    for (int j=0; j<columns; j++) {
      fscanf(image, "%d", &element);
      result = element + p;

      if (result > maxGray) {
        result = maxGray;
      }

      fprintf(lightenImage, "%d\n", result);
    }
  }

  fclose(lightenImage);
}

void negative(FILE * image, int rows, int columns, int maxGray, int p) {
  FILE * negativeImage = fopen("lena256-negativo.pgm", "w");
  fprintf(negativeImage, "P2\n%d %d\n%d\n", rows, columns, maxGray);

  int element, result;
  for (int i=0; i<rows; i++) {
    for (int j=0; j<columns; j++) {
      fscanf(image, "%d", &element);
      result = maxGray - element;
      fprintf(negativeImage, "%d\n", result);
    }
  }

  fclose(negativeImage);
}

void rotate90(FILE * image, int rows, int columns, int maxGray, int p) {
  FILE * rotate90Image = fopen("lena256-rotacionado90.pgm", "w");
  fprintf(rotate90Image, "P2\n%d %d\n%d\n", columns, rows, maxGray);

  int element;
  for (int i=0; i<columns; i++) {
    for (int j=0; j<rows; j++) {
      fscanf(image, "%d", &element);
      fprintf(rotate90Image, "%d\n", element);
    }
  }

  fclose(rotate90Image);
}

void rotate180(FILE * image, int rows, int columns, int maxGray, int p) {
  FILE * rotate180Image = fopen("lena256-rotacionado180.pgm", "w");
  fprintf(rotate180Image, "P2\n%d %d\n%d\n", rows, columns, maxGray);

  int element;
  for (int i=0; i<rows; i++) {
    for (int j=0; j<columns; j++) {
      fscanf(image, "%d", &element);
      fprintf(rotate180Image, "%d\n", element);
    }
  }

  fclose(rotate180Image);
}

void rotate270(FILE * image, int rows, int columns, int maxGray, int p) {
  FILE * rotate270Image = fopen("lena256-rotacionado270.pgm", "w");
  fprintf(rotate270Image, "P2\n%d %d\n%d\n", columns, rows, maxGray);

  int element;
  for (int i=0; i<columns; i++) {
    for (int j=0; j<rows; j++) {
      fscanf(image, "%d", &element);
      fprintf(rotate270Image, "%d\n", element);
    }
  }

  fclose(rotate270Image);
}

void mirror(FILE * image, int rows, int columns, int maxGray, int p) {
  FILE * mirrorImage = fopen("lena256-espelhado.pgm", "w");
  fprintf(mirrorImage, "P2\n%d %d\n%d\n", rows, columns, maxGray);

  int element;
  for (int i=0; i<rows; i++) {
    for (int j=0; j<columns; j++) {
      fscanf(image, "%d", &element);
      fprintf(mirrorImage, "%d\n", element);
    }
  }

  fclose(mirrorImage);
}

typedef struct {
  char * name;
  void (*operationFunction)(FILE * image, int rows, int columns, int maxGray, int p);
} Operation;

static struct option options[] = {
  {"darken", required_argument, 0, 'd'},
  {"brighten", required_argument, 0, 'b'},
  {"negative", no_argument, 0, 'n'},
  {"rotate90", no_argument, 0, 0},
  {"rotate180", no_argument, 0, 0},
  {"rotate270", no_argument, 0, 0},
  {"mirror", no_argument, 0, 'm'}
};

int main(int argc, char *argv[]) {
  int opt, p = -1;
  char * operation = "\0";

  Operation operations[] = {
    {"darken", darken},
    {"brighten", brighten},
    {"negative", negative},
    {"rotate90", rotate90},
    {"rotate180", rotate180},
    {"rotate270", rotate270},
    {"mirror", mirror}
  };

  // Get options
  int option_index = 0;
  while ((opt = getopt_long(argc, argv, "d:b:nm", options, &option_index)) != -1) {
    switch (opt) {
      case 'd':
        operation = "darken";
        p = atoi(optarg);
        break;
      case 'b':
        operation = "brighten";
        p = atoi(optarg);
        break;
      case 'n':
        operation = "negative";
        break;
      case 'm':
        operation = "mirror";
        break;
      case 0:
        if (strcmp(options[option_index].name, "rotate90") == 0) {
          operation = "rotate90";
        } else if (strcmp(options[option_index].name, "rotate180") == 0) {
          operation = "rotate180";
        } else if (strcmp(options[option_index].name, "rotate270") == 0) {
          operation = "rotate270";
        }
        break;
    }
  }

  printf("p: %d\n", p);
  printf("operation: %s\n", operation);

  // Load image
  FILE * image = fopen("lena256.pgm", "r");

  if (image == NULL) {
    printf("Erro ao abrir o arquivo\n");
    return 1;
  }

  char * imageType = malloc(2 * sizeof(char));
  fscanf(image, "%s", imageType);

  if (strcmp(imageType, "P2") != 0) {
    printf("O arquivo não é do tipo P2\n");
    return 1;
  }

  int rows, columns;
  fscanf(image, "%d %d", &rows, &columns);
  int maxGray;
  fscanf(image, "%d", &maxGray);

  // INIT: Execute operation
  int ok = 0;
  for (int i=0; i<sizeof(operations) / sizeof(operations[0]); i++) {
    if (strcmp(operation, operations[i].name) == 0) {
      operations[i].operationFunction(image, rows, columns, maxGray, p);
      ok = 1;
      break;
    }
  }

  if (!ok) {
    printf("Operação inválida\n");
    return 1;
  }

  fclose(image);

  return 0;
}
