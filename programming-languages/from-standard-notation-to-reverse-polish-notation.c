#include<stdlib.h>
#include<stdio.h>
#include<string.h>

// 1+3/3

// 1. [1] -- []
// 2. [1] -- [+]
// 3. [1, 3] -- [+]
// 4. [1, 3] -- [+, /]
// 5. [1, 3, 3] -- [+, /]
// 6. [1, 3, 3, /, +]

// (1+2)/3

// 1. [1] -- []
// 2. [1] -- [+]
// 3. [1, 2] -- [+]
// 4. [1, 2, +] -- []
// 5. [1, 2, +] -- [/]
// 6. [1, 2, +, 3] -- [/]
// 7. [1, 2, +, 3, /] -- []

// (1+(7-1))/3

// 1. [1] -- []
// 2. [1] -- [+]
// 3. [1, 7] -- [+]
// 4. [1, 7] -- [+, -]
// 5. [1, 7, -, +] -- []
// 6. [1, 7, -, +] -- []
// 7. [1, 7, -, +] -- [/]
// 8. [1, 7, -, +, 3] -- [/]
// 9. [1, 7, -, +, 3, /] -- []

#define NOTATION_MAX_LENGTH 40

char *fromStandardNotationToReversePolishNotation(char *input_notation) {
  if (strlen(input_notation) > NOTATION_MAX_LENGTH) {
    printf("%s: input_notation is bigger than NOTATION_MAX_LENGTH (%d)\n", __func__, NOTATION_MAX_LENGTH);
    return "\0";
  }

  char *signal_vector = malloc(sizeof(char) * strlen(input_notation));
  char *result_vector = malloc(sizeof(char) * strlen(input_notation));

  int signal_vector_last = -1;
  int result_vector_last = -1;

  for (int i = 0; input_notation[i] != '\0'; i++) {
    if (
      input_notation[i] != '+' &&
      input_notation[i] != '-' &&
      input_notation[i] != '*' &&
      input_notation[i] != '/' &&
      input_notation[i] != '(' &&
      input_notation[i] != ')'
    ) {
      result_vector_last++;
      result_vector[result_vector_last] = input_notation[i];

      if (input_notation[i+1] == '\0') {
        while (signal_vector_last > -1) {
          result_vector_last++;
          result_vector[result_vector_last] = signal_vector[signal_vector_last];

          signal_vector[signal_vector_last] = '\0';
          signal_vector_last--;
        }
      }

      continue;
    }

    if (input_notation[i] != '(' && input_notation[i] != ')') {
      signal_vector_last++;
      signal_vector[signal_vector_last] = input_notation[i];

      continue;
    }

    if (input_notation[i] == ')') {
      while (signal_vector_last > -1) {
        result_vector_last++;
        result_vector[result_vector_last] = signal_vector[signal_vector_last];

        signal_vector[signal_vector_last] = '\0';
        signal_vector_last--;
      }
    }
  }

  free(signal_vector);

  return result_vector;
}

void main() {
  char expression[NOTATION_MAX_LENGTH+1];

  printf("expression: ");
  fgets(expression, sizeof(expression), stdin);
  expression[strlen(expression)-1] = '\0';

  printf("result:     %s\n", fromStandardNotationToReversePolishNotation(expression));
}