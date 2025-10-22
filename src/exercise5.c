#include <stdio.h>
#include <stdlib.h>
int main() {
    float a[10][3];
    float b[3][10];
    float c[10][10];
    int i, j, k;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 10; j++) {
            scanf("%f", &b[i][j]);
        }
    }

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            c[i][j] = 0;
            for (k = 0; k < 3; k++) {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%.2f", c[i][j]);
            if (i != 9 || j != 9) printf(" ");
        }
    }
    printf("\n");

    return 0;
}
