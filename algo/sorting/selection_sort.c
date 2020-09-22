#include <stdio.h>

#define MAX 10

void insertion_sort(int *array, int n);

int main() {
  int i, n;
  int array[MAX];

  printf("\nEnter Size of Array : ");

  scanf("%d", &n);

  printf("\nEnter Elements of Array : ");
  for (i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  insertion_sort(array, n);

  printf("\nSorted Array : ");

  for (i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  return 0;
}

void insertion_sort(int *array, int n) {
  int idx, temp;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i; j < n; j++) {
      if (array[i] > array[j])
        idx = j;
    }
    temp = array[i];
    array[i] = array[idx];
    array[idx] = temp;
  }
}
