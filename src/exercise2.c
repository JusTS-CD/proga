#include <stdio.h>

int main() {
    float a[10];
    int i;

    for (i = 0; i < 10; i++) {
        scanf("%f", &a[i]);
    }

    for (i = 9; i >= 0; i--) {
        printf("%f", a[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");

    return 0;
}
