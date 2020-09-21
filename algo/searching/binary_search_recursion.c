#include <stdio.h>

#define MAX 20

int binary(int array[], int low, int high, int key);

int main() {
  int i, n = MAX - 1, key, index, low, high;
  int array[MAX];

  printf("\nEnter Size of Array : ");
  scanf("%d", &n);
  printf("\nEnter Elements of Array in sorted order : ");
  for (i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }
  printf("\nEnter element to search : ");
  scanf("%d", &key);

  low = 0;
  high = n-1;

  index = binary(array, low, high, key);

  if (index != -1) {
    printf("Found %d at pos %d", key, index + 1);
  } else {
    printf("\nGiven Array Doesnt Contain Element %d ", key);
  }

  printf("\n");
  return 0;
}

int binary(int array[], int low, int high, int key){
    int mid = low + (high - low) / 2; // prevents overflow

    if (low>high) {
      return -1;
    }
    else if (array[mid] == key) {
      return mid;
    }
    else if (array[mid] < key) {
     return binary(array, mid + 1, high, key);
    }
    else { // array[mid] > key
     return binary(array, low, mid - 1, key);
    }
}
