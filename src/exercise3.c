#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    float a[10], b[10];
    int k;
    int n = 10;

    k = atoi(argv[1]);

    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }

    if (k > 0) {
        k = k % n;
    } else if (k < 0) {
        k = n + (k % n);
        if (k == n) k = 0;
    }

    for (int i = 0; i < n; i++) {
        b[(i + k) % n] = a[i];
    }

    for (int i = 0; i < n; i++) {
        printf("%f ", b[i]);
    }

    return 0;
}
