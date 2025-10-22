#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
     
    float a[10];
    float x = atof(argv[11]);
    int k = atoi(argv[12]);

    for (int i = 0; i < 10; i++) {
        a[i] = atof(argv[i + 1]);
    }
    
    for (int i = 9; i > k; i--) {
        a[i] = a[i - 1];
    }
    a[k] = x;

    for (int i = 0; i < 10; i++) {
        printf("%f ", a[i]);
    }
}
