#include <stdio.h>

void sort(int *a, int size) {
  if (size == 0) {
    return;
  }

  /*
   * Shift a[x..i-1] right where a[x] > a[i] and a[x-1] <= a[i],
   * and move a[i] to a[x].
   * */
  for (int i = 1; i < size; i++) {
    int key = a[i];
    int j = i - 1;
    for (; (j >= 0) && (a[j] > key); j--) {
      a[j+1] = a[j];

    }
    /*
     * Note that j is decremented by for statement after hitting j==x.
     * */
    a[j+1] = key;
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
