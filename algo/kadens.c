#include <limits.h>
#include <stdio.h>

// max sum subarray in o(n)

int max(int a, int b) { return a > b ? a : b; }

int kadens(int n, int *array);

int main() {
    int n;
    printf("Enter Size of Array : ");
    scanf("%d", &n);
    int array[n];
    printf("Enter Elements of Array : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    int maxsum = kadens(n, array);
    printf("%d",maxsum);
    return 0;
}

int kadens(int n, int *array) {
    int maxsum = INT_MIN;
    int a = 0;
    for (int i = 0; i < n; i++) {
        a += array[i];
        maxsum = max(a, maxsum);
        a = max(a, 0);
    }

    return maxsum;
}
