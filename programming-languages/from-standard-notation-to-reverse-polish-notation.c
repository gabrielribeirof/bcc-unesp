#include<stdlib.h>
#include<stdio.h>
#include<string.h>

// 1+3/3

// 1. [1] -- []
// 2. [1] -- [+]
// 3. [1, 3] -- [+]
// 4. [1, 3] -- [+, /]
// 5. [1, 3, 3] -- [+, /]
// 6. [1, 3, 3, /, +] -- []

// 1/3+3

// 1. [1] -- []
// 2. [1] -- [/]
// 3. [1, 3] -- [/]
// 4. [1, 3, /] -- []
// 5. [1, 3, /] -- [+]
// 6. [1, 3, /, 3, +] -- []

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
// 5. [1, 7, 1, -, +] -- []
// 6. [1, 7, 1, -, +] -- []
// 7. [1, 7, 1, -, +] -- [/]
// 8. [1, 7, 1, -, +, 3] -- [/]
// 9. [1, 7, 1, -, +, 3, /] -- []

#define NOTATION_MAX_LENGTH 40
#define ENABLE_INSTRUCTION_PRINT 1

void vector_print(char *target) {
  if (target[0] == '\0') {
    printf("[]");
    return;
  }

  printf("[ %c", target[0]);

  for (int i=1; target[i] != '\0'; i++) {
    printf(" , %c", target[i]);
  }
  
  printf(" ]");
}

void instruction_print(int *instruction, char *result_vector, char *signal_vector) {
  if (ENABLE_INSTRUCTION_PRINT == 0) return;

  printf("%d. ", *instruction);
  vector_print(result_vector);
  printf(" -- ");
  vector_print(signal_vector);
  printf("\n");

  (*instruction)++;
}

char *fromStandardNotationToReversePolishNotation(char *input_notation) {
  if (strlen(input_notation) > NOTATION_MAX_LENGTH) {
    printf("%s: input_notation is bigger than NOTATION_MAX_LENGTH (%d)\n", __func__, NOTATION_MAX_LENGTH);
    return '\0';
  }

  char *signal_vector = malloc(sizeof(char) * strlen(input_notation));
  char *result_vector = malloc(sizeof(char) * (strlen(input_notation) * 2));

  int instruction = 1;
  int signal_vector_last = -1;
  int result_vector_last = -1;
  int precedence = 0;

  for (int i=0; input_notation[i] != '\0'; i++) {
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

      if (precedence == 1 && input_notation[i+1] != '\0') {
        if (signal_vector_last > -1) {
          result_vector_last++;
          result_vector[result_vector_last] = signal_vector[signal_vector_last];

          signal_vector[signal_vector_last] = '\0';
          signal_vector_last--;
        }

        instruction_print(&instruction, result_vector, signal_vector);

        precedence = 0;
        continue;
      }

      if (input_notation[i+1] == '\0') {
        while (signal_vector_last > -1) {
          result_vector_last++;
          result_vector[result_vector_last] = signal_vector[signal_vector_last];

          signal_vector[signal_vector_last] = '\0';
          signal_vector_last--;
        }
      }

      instruction_print(&instruction, result_vector, signal_vector);

      continue;
    }

    if (input_notation[i] != '(' && input_notation[i] != ')') {
      if (input_notation[i] == '/' || input_notation[i] == '*' && precedence == 0) {
        precedence = 1;
      }

      signal_vector_last++;
      signal_vector[signal_vector_last] = input_notation[i];

      instruction_print(&instruction, result_vector, signal_vector);

      continue;
    }

    if (input_notation[i] == ')') {
      while (signal_vector_last > -1) {
        result_vector_last++;
        result_vector[result_vector_last] = signal_vector[signal_vector_last];

        signal_vector[signal_vector_last] = '\0';
        signal_vector_last--;
      }

      instruction_print(&instruction, result_vector, signal_vector);
    }
  }

  free(signal_vector);

  return result_vector;
}

void main() {
  char expression[NOTATION_MAX_LENGTH];

  printf("expression: ");
  fgets(expression, sizeof(expression), stdin);
  expression[strlen(expression)-1] = '\0';

  printf("\nresult: %s\n", fromStandardNotationToReversePolishNotation(expression));
}