#include<stdio.h>

int main() {
  FILE * matriz1 = fopen("matriz1.txt", "r");
  FILE * matriz2 = fopen("matriz2.txt", "r");

  if (matriz1 == NULL || matriz2 == NULL) {
    printf("Erro ao abrir os arquivos\n");
    return 1;
  }

  // Somar matrizes
  FILE * sumResultFile = fopen("sum.txt", "w");

  int rows1, columns1;
  fscanf(matriz1, "%d %d", &rows1, &columns1);

  int rows2, columns2;
  fscanf(matriz2, "%d %d", &rows2, &columns2);

  if (rows1 != rows2 || columns1 != columns2) {
    printf("As matrizes não possuem o mesmo tamanho\n");
    return 1;
  }

  int element1, element2, result;
  for (int i=0; i<rows1; i++) {
    for (int j=0; j<columns1; j++) {
      fscanf(matriz1, "%d", &element1);
      fscanf(matriz2, "%d", &element2);
      result = element1 + element2;

      if (result > 255) {
        result = 255;
      }

      fprintf(sumResultFile, "%d\n", result);
    }
  }

  fclose(sumResultFile);

  rewind(matriz1);
  rewind(matriz2);

  // Subtrair matrizes
  FILE * subResultFile = fopen("sub.txt", "w");

  for (int i=0; i<rows1; i++) {
    for (int j=0; j<columns1; j++) {
      fscanf(matriz1, "%d", &element1);
      fscanf(matriz2, "%d", &element2);
      result = element1 - element2;

      if (result < 0) {
        result = 0;
      }

      fprintf(subResultFile, "%d\n", result);
    }
  }

  fclose(subResultFile);

  fclose(matriz1);
  fclose(matriz2);

  return 0;
}