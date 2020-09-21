#include <stdio.h>

#define MAX 20

int main() {
  int i, n = MAX - 1, key;
  int array[MAX];

  printf("\nEnter Size of Array : ");
  scanf("%d", &n);
  printf("\nEnter Elements of Array : ");
  for (i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }
  printf("\nEnter element to search : ");
  scanf("%d", &key);

  for (i = 0; i < n; i++) {
    if (array[i] == key) {
      printf("\nFound %d at pos : %d", key, i + 1);
      return 0;
    }
  }

  printf("\nGiven Array Doesnt Contain Element %d ", key);

  printf("\n");
  return 0;
}
