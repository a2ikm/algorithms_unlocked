#include <stdio.h>
#include <stdlib.h>

int partition(int *a, int p, int r) {
  // before: [p]smallers, [q]largers, [r]pivot
  int q = p; // start of largers
  int tmp;
  for (int u = p; u < r; u++) { // scan unknowns
    if (a[u] <= a[r]) {
      tmp = a[q];
      a[q] = a[u];
      a[u] = tmp;
      q++;
    }
  }

  // replace [q]largers with [r]pivot
  // after:  [p]smallers, [q]pivot, [q+1]largers
  tmp = a[q];
  a[q] = a[r];
  a[r] = tmp;
  return q;
}

void quick_sort(int *a, int p, int r, int lv) {
  if (p >= r) {
    return;
  }

  int q = partition(a, p, r);
  quick_sort(a, p, q - 1, lv + 1);
  quick_sort(a, q + 1, r, lv + 1);
}

void sort(int *a, int size) {
  if (size == 0) {
    return;
  }

  quick_sort(a, 0, size - 1, 0);
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
