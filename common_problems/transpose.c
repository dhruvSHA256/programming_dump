#include <stdio.h>

#define MAX 20

int main() {
    int i, j, r, c;
    int a[MAX][MAX], b[MAX][MAX];
    printf("Enter number of rows : ");
    scanf("%d", &r);
    printf("Enter number of columns : ");
    scanf("%d", &c);
    printf("Enter Matrix : ");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            b[j][i] = a[i][j];
        }
    }

    printf("\nTranspose of MAtrix :\n");

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
