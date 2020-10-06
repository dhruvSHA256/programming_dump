#include <stdio.h>

#define MAX 20

int linear(int array[], int n, int key);

int main() {
    int i, n = MAX - 1, key, index;
    int array[MAX];

    printf("\nEnter Size of Array : ");
    scanf("%d", &n);
    printf("\nEnter Elements of Array : ");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    printf("\nEnter element to search : ");
    scanf("%d", &key);

    index = linear(array, n, key);

    if (index != -1) {
        printf("Found %d at pos %d", key, index + 1);
    } else {
        printf("\nGiven Array Doesnt Contain Element %d ", key);
    }

    printf("\n");
    return 0;
}

int linear(int array[], int n, int key) {
    int i, idx = -1;
    for (i = 0; i < n; i++) {
        if (array[i] == key) {
            idx = i;
            break;
        }
    }
    return idx;
}
