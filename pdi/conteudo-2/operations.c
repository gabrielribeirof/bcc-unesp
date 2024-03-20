#include "operations.h"

void darken(FILE * image, int rows, int columns, int maxGray, int p) {
  FILE * darkenImage = fopen("output/lena256-escurecido.pgm", "w");
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
  FILE * lightenImage = fopen("output/lena256-clareado.pgm", "w");
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

void negative(FILE * image, int rows, int columns, int maxGray) {
  FILE * negativeImage = fopen("output/lena256-negativo.pgm", "w");
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

void rotate90(FILE * image, int rows, int columns, int maxGray) {
  FILE * rotate90Image = fopen("output/lena256-rotacionado90.pgm", "w");
  fprintf(rotate90Image, "P2\n%d %d\n%d\n", columns, rows, maxGray);

  int element;
  int imageMatrix[rows][columns];
  for (int i=0; i<rows; i++) {
    for (int j=0; j<columns; j++) {
      fscanf(image, "%d", &element);
      imageMatrix[i][j] = element;
    }
  }

  for (int i=columns-1; i>=0; i--) {
    for (int j=0; j<rows; j++) {
      fprintf(rotate90Image, "%d\n", imageMatrix[j][i]);
    }
  }

  fclose(rotate90Image);
}

void rotate180(FILE * image, int rows, int columns, int maxGray) {
  FILE * rotate180Image = fopen("output/lena256-rotacionado180.pgm", "w");
  fprintf(rotate180Image, "P2\n%d %d\n%d\n", rows, columns, maxGray);

  int element;
  int imageMatrix[rows][columns];
  for (int i=0; i<rows; i++) {
    for (int j=0; j<columns; j++) {
      fscanf(image, "%d", &element);
      imageMatrix[i][j] = element;
    }
  }

  for (int i=rows-1; i>=0; i--) {
    for (int j=columns-1; j>=0; j--) {
      fprintf(rotate180Image, "%d\n", imageMatrix[i][j]);
    }
  }

  fclose(rotate180Image);
}

void rotate270(FILE * image, int rows, int columns, int maxGray) {
  FILE * rotate90Image = fopen("output/lena256-rotacionado270.pgm", "w");
  fprintf(rotate90Image, "P2\n%d %d\n%d\n", columns, rows, maxGray);

  int element;
  int imageMatrix[rows][columns];
  for (int i=0; i<rows; i++) {
    for (int j=0; j<columns; j++) {
      fscanf(image, "%d", &element);
      imageMatrix[i][j] = element;
    }
  }

  for (int i=0; i<columns; i++) {
    for (int j=rows-1; j>=0; j--) {
      fprintf(rotate90Image, "%d\n", imageMatrix[j][i]);
    }
  }

  fclose(rotate90Image);
}

void mirror(FILE * image, int rows, int columns, int maxGray) {
  FILE * mirrorImage = fopen("output/lena256-espelhado.pgm", "w");
  fprintf(mirrorImage, "P2\n%d %d\n%d\n", rows, columns, maxGray);

  int element;
  int imageMatrix[rows][columns];
  for (int i=0; i<rows; i++) {
    for (int j=0; j<columns; j++) {
      fscanf(image, "%d", &element);
      imageMatrix[i][j] = element;
    }
  }

  for (int i=0; i<rows; i++) {
    for (int j=columns-1; j>=0; j--) {
      fprintf(mirrorImage, "%d\n", imageMatrix[i][j]);
    }
  }

  fclose(mirrorImage);
}