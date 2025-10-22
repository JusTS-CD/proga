#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    float a[10];
    float x;
    int k, i;

    if (argc != 3) {
        printf("Usage: ./exercise4 X K\n");
        return 1;
    }

    x = atof(argv[1]);
    k = atoi(argv[2]);

    for (i = 0; i < 10; i++) {
        scanf("%f", &a[i]);
    }

    for (i = 9; i > k; i--) {
        a[i] = a[i - 1];
    }
    a[k] = x;

    for (i = 0; i < 10; i++) {
        printf("%.0f", a[i]);
        if (i < 9) printf(" ");
    }
    printf("\n");

    return 0;
}
