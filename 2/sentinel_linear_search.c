#include <stdio.h>
#define SIZE 100
#define NOT_FOUND -1

int linear_search(int *a, int size, int target) {
  int last = a[size-1];
  a[size-1] = target;

  int i = 0;
  while (a[i] != target) {
    i++;
  }

  a[size-1] = last;
  if (i < size-1 || a[size-1] == target) {
    return i;
  } else {
    return NOT_FOUND;
  }
}

int main(int argc, char **args) {
  int a[SIZE], result;
  for (int i = 0; i < SIZE; i++) {
    a[i] = i;
  }

  result = linear_search(a, SIZE, 8);
  if (result != 8) {
    printf("Expected %d but got %d", 8, result);
    return 1;
  }

  result = linear_search(a, SIZE, 99);
  if (result != 99) {
    printf("Expected %d but got %d", 99, result);
    return 1;
  }

  result = linear_search(a, SIZE, 100);
  if (result != NOT_FOUND) {
    printf("Expected %d but got %d", NOT_FOUND, result);
    return 1;
  }

  return 0;
}
