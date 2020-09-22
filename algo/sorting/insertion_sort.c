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
  int temp_idx, temp;
  for (int i = 1; i < n; i++) {
    temp_idx = i - 1;
    temp = array[i];
    while (temp_idx >= 0 && array[temp_idx] > temp) {
      array[temp_idx + 1] = array[temp_idx];
      temp_idx--;
    }
    array[temp_idx + 1] = temp;
  }
}
