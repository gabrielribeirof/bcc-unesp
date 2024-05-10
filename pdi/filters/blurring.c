#include<stdio.h>

// Tamanho da matriz blur de ordem ímpar
#define BLURRING_SIZE 15

void main() {
  FILE *input = fopen("input/blurring.pgm", "rb");

  if (input == NULL) {
    printf("Error: File not found\n");
    return;
  }

  // Carregando header do .PGM
  int rows, columns, maxGray;

  fscanf(input, "P2\n%d %d\n%d\n", &columns, &rows, &maxGray);

  // Calcula o tamanho 
  int blurArrayPaddingSize = (BLURRING_SIZE - 1) / 2;

  int rowsWithPadding = rows + (blurArrayPaddingSize * 2);
  int columnsWithPadding = columns + (blurArrayPaddingSize * 2);

  // Preenche com a cor preta as bordas da imagem de entrada com tamanho igual ao padding da matriz de blur
  int imageMatrix[rowsWithPadding][columnsWithPadding];

  int i, j;

  for (i = 0; i < rowsWithPadding; i++) {
    for (j = 0; j < blurArrayPaddingSize; j++) {
      imageMatrix[i][j] = 0;
      imageMatrix[i][columnsWithPadding - 1 - j] = 0;
    }
  }

  for (i = 0; i < columnsWithPadding; i++) {
    for (j = 0; j < blurArrayPaddingSize; j++) {
      imageMatrix[j][i] = 0;
      imageMatrix[rowsWithPadding - 1 - j][i] = 0;
    }
  }

  // Carrega imagem na memória pulando as borda preta colocada anteriormente
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      fscanf(input, "%d", &imageMatrix[i+blurArrayPaddingSize][j+blurArrayPaddingSize]);
    }
  }

  int resultMatrix[rows][columns];

  for (i = blurArrayPaddingSize; i < rowsWithPadding - blurArrayPaddingSize; i++) {
    for (j = blurArrayPaddingSize; j < columnsWithPadding - blurArrayPaddingSize; j++) {
      int sum = 0;

      for (int k = -blurArrayPaddingSize; k < blurArrayPaddingSize+1; k++) {
        for (int l = -blurArrayPaddingSize; l < blurArrayPaddingSize+1; l++) {
          sum += imageMatrix[i + k][j + l];
        }
      }

      resultMatrix[i-blurArrayPaddingSize][j-blurArrayPaddingSize] = sum / (BLURRING_SIZE*BLURRING_SIZE);
    }
  }

  FILE *output = fopen("output/blurring_blur.pgm", "wb");

  fprintf(output, "P2\n%d %d\n%d\n", columns, rows, maxGray);

  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      fprintf(output, "%d\n", resultMatrix[i][j]);
    }
  }

  fclose(input);
  fclose(output);
}