#include <stdio.h>

void sort(int *a, int size) {
  if (size == 0) {
    return;
  }

  /*
   * Replace a[i] with smallest value in i..size.
   * */
  for (int i = 0; i < size; i++) {
    int tmp, sm = i;
    for (int j = i; j < size; j++) {
      if (a[j] < a[sm]) {
        sm = j;
      }
    }
    tmp = a[i];
    a[i] = a[sm];
    a[sm] = tmp;
  }
}

int main(int argc, char **args) {
  int a[10] = { 1, 9, 2, 0, 3, 8, 4, 7, 5, 6 };
  sort(a, 10);

  for (int i = 0; i < 10; i++) {
    if (a[i] != i) {
      printf("Expected %d but got %d", i, a[i]);
      return 1;
    }
  }

  return 0;
}
