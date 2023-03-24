#include<stdio.h>

#define MAX 8

typedef struct {
  int elements[MAX];
  int length;
} list;

list init() {
  list L;
  L.length = 0;

  return L;
}

void insert(list *target, int element, int index) {
  if ((target->length + 1) > MAX) {
    return;
  }

  for (int i=(target->length - 1); i>=index; i--) {
    target->elements[i+1] = target->elements[i];
  }

  target->elements[index] = element;
  target->length++;
}

void delete(list *target, int index) {
  for (int i=index; i<(target->length - 1); i++) {
    target->elements[i] = target->elements[i+1];
  }

  target->elements[target->length - 1] = '\0';
  target->length--;
}

void print(list *target) {
  printf("[ ");
  printf("%d", target->elements[0]);

  for (int i=1; i<target->length; i++) {
    printf(", %d", target->elements[i]);
  }

  printf(" ]\n");
}

int main() {
  list L = init();

  insert(&L, 10, 0);
  insert(&L, 12, 1);
  insert(&L, 13, 0);
  insert(&L, 14, 3);
  delete(&L, 3);
  print(&L);

  return 0;
}
