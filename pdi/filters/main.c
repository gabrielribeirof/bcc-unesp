#include<stdio.h>

#define IMAGE_VERSION 0

int filterMask[3][3] = {
  {-1, -1, -1},
  {-1, 8, -1},
  {-1, -1, -1}
};

void main() {
  FILE *input = fopen("input/blurry_moon.pgm", "rb");

  if (input == NULL) {
    printf("Error: File not found\n");
    return;
  }

  int rows, columns, maxGray;

  fscanf(input, "P2\n%d %d\n%d\n", &columns, &rows, &maxGray);

  int imageMatrix[rows][columns];

  int i, j;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      fscanf(input, "%d", &imageMatrix[i][j]);
    }
  }

  int resultMatrix[rows][columns];

  for (i = 1; i < rows - 1; i++) {
    for (j = 1; j < columns - 1; j++) {
      int sum = 0;

      for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
          sum += filterMask[k][l] * imageMatrix[i + k - 1][j + l - 1];
        }
      }

      resultMatrix[i][j] = sum;
    }
  }

  for (i = 0; i < rows; i++) {
    resultMatrix[i][0] = 0;
    resultMatrix[i][columns - 1] = 0;
  }

  for (j = 0; j < columns; j++) {
    resultMatrix[0][j] = 0;
    resultMatrix[rows - 1][j] = 0;
  }

  FILE *output = fopen("output/blurry_moon_laplaciano.pgm", "wb");

  fprintf(output, "P2\n%d %d\n%d\n", columns, rows, maxGray);

  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      fprintf(output, "%d\n", resultMatrix[i][j]);
    }
  }

  fclose(input);
  fclose(output);
}