#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int i, j, matrix[500][500];

int main(void) {
    int N;

    while(1) {
        scanf("%d", &N);
        if(N == 0) break;

        for(i = 0; i < N; i++) {
            int sumr = 0;
            for(j = 0; j < N; j++) {
                scanf("%d", &matrix[i][j]);
                sumr += matrix[i][j];
            }
            matrix[i][j] = sumr;
        }
    }

    return 0;
}
