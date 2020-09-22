#include <stdio.h>

#define MAX 10

void bubble_sort(int *array, int n);

int main() {
  int i, n;
  int array[MAX];

  printf("\nEnter Size of Array : ");

  scanf("%d", &n);

  printf("\nEnter Elements of Array : ");
  for (i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  bubble_sort(array, n);

  printf("\nSorted Array : ");

  for (i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  return 0;
}

void bubble_sort(int *array, int n) {

  for (int i = 0; i < n - 1; i++) {
    for (int j = i; j < n; j++) {
      if (array[i] > array[j]) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}
