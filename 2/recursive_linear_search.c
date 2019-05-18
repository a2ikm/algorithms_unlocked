#include <stdio.h>
#define SIZE 100
#define NOT_FOUND -1

int linear_search_internal(int *a, int size, int target, int i) {
  if (i > size) {
    return NOT_FOUND;
  } else {
    if (a[i] == target) {
      return i;
    } else {
      return linear_search_internal(a, size, target, i+1);
    }
  }
}

int linear_search(int *a, int size, int target) {
  return linear_search_internal(a, size, target, 0);
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

  result = linear_search(a, SIZE, 100);
  if (result != NOT_FOUND) {
    printf("Expected %d but got %d", NOT_FOUND, result);
    return 1;
  }

  return 0;
}
