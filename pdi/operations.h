#ifndef IMAGE_OPERATIONS_H
#define IMAGE_OPERATIONS_H

#include <stdio.h>

void darken(FILE * image, int rows, int columns, int maxGray, int p);
void brighten(FILE * image, int rows, int columns, int maxGray, int p);
void negative(FILE * image, int rows, int columns, int maxGray);
void rotate90(FILE * image, int rows, int columns, int maxGray);
void rotate180(FILE * image, int rows, int columns, int maxGray);
void rotate270(FILE * image, int rows, int columns, int maxGray);
void mirrorh(FILE * image, int rows, int columns, int maxGray);
void mirrorv(FILE * image, int rows, int columns, int maxGray);
void binarization(FILE * image, int rows, int columns, int maxGray, int k);
void middleGrayLevel(FILE * image, int rows, int columns, int maxGray, int l);

typedef struct {
  char * name;
  void (*operationFunction)(FILE * image, int rows, int columns, int maxGray, int p);
} operation_type;

#endif