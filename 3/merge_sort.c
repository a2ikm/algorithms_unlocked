#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  int *a1 = malloc(n1 * sizeof(int));
  int *a2 = malloc(n2 * sizeof(int));

  for (int i = 0; i < n1; i++) {
    a1[i] = a[p+i];
  }
  for (int i = 0; i < n2; i++) {
    a2[i] = a[q+1+i];
  }

  // pick a1[i] or a2[j] which is larger as a[k]
  int i = 0; /* < n1 */
  int j = 0; /* < n2 */
  for (int k = p; k <= r; k++) {
    if (i >= n1) { // a1 is empty
      a[k] = a2[j];
      j++;
    } else if (j >= n2) { // a2 is empty
      a[k] = a1[i];
      i++;
    } else if (a1[i] <= a2[j]) {
      a[k] = a1[i];
      i++;
    } else {
      a[k] = a2[j];
      j++;
    }
  }

  free(a1);
  free(a2);
}

void merge_sort(int *a, int p, int r, int lv) {
  if (p >= r) {
    return;
  }

  int q = (r + p)/2;
  merge_sort(a, p, q, lv + 1);
  merge_sort(a, q + 1, r, lv + 1);
  merge(a, p, q, r);
}

void sort(int *a, int size) {
  if (size == 0) {
    return;
  }

  merge_sort(a, 0, size - 1, 0);
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
