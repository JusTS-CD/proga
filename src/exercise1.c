#include <stdio.h>

int main() {
    float a[10];
    float sum = 0;
    int i;

    for (i = 0; i < 10; i++) {
        scanf("%f", &a[i]);
        sum = sum + a[i];
    }

    printf("%.2f\n", sum / 10);
    return 0;
}
