#include <stdio.h>

#define MAX 20

int binary(int array[], int n, int key);

int main() {
  int i, n = MAX - 1, key, index;
  int array[MAX];

  printf("\nEnter Size of Array : ");
  scanf("%d", &n);
  printf("\nEnter Elements of Array in sorted order : ");
  for (i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }
  printf("\nEnter element to search : ");
  scanf("%d", &key);

  index = binary(array, n, key);

  if (index != -1) {
    printf("Found %d at pos %d", key, index + 1);
  } else {
    printf("\nGiven Array Doesnt Contain Element %d ", key);
  }

  printf("\n");
  return 0;
}

int binary(int array[], int n, int key) {
  int idx, low, high, mid;

  idx = -1;
  low = 0;
  high = n - 1;

  while (low <= high) {
    mid = low + (high - low) / 2; // prevents overflow
    if (array[mid] == key) {
      idx = mid;
      break;
    } else if (array[mid] < key) {
      low = mid + 1;
    } else { // array[mid] > key
      high = mid - 1;
    }
  }
  return idx;
}
