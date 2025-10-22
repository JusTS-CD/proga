#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    float a[10], b[10];
    int i, k;

    if (argc != 2) {
        printf("Usage: ./exercise3 K\n");
        return 1;
    }

    k = atoi(argv[1]);

    for (i = 0; i < 10; i++) {
        scanf("%f", &a[i]);
    }

    int n = 10;
    if (k > 0) {
        k = k % n;
    } else if (k < 0) {
        k = n + (k % n);
        if (k == n) k = 0;
    }

    for (i = 0; i < n; i++) {
        b[(i + k) % n] = a[i];
    }

    for (i = 0; i < n; i++) {
        printf("%.0f", b[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");

    return 0;
}
