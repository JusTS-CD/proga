#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    float a[10];
    float b[10];
    int k = atoi(argv[11]);

    for (int i = 0; i < 10; i++) {
        a[i] = atof(argv[i + 1]);
    }

    int n = 10;

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
