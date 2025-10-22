#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int a[10][3];
    int b[3][10];
    int c[10][10] = {0};

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d ", &a[i][j]);
        }
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d ", &b[i][j]);
        }
    }
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 3; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", c[i][j]);
        }
    }
}
