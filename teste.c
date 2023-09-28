#include <stdio.h>

void matrizMemPos (int m[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%p ", &m[i][j]);
        }
        printf("\n");
    }
}

void main() {
    int m[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    matrizMemPos(m);
}