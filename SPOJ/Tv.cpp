#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int n, m, matrix[1010][1010], x, y, sumx, sumy, teste = 1;

int main(void) {
    freopen("i.in", "r", stdin);
    while(scanf("%d%d", &n, &m) && !(n == 0 && m == 0)) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        sumx = sumy = 0;
        printf("Teste %d\n", teste++);
        while(scanf("%d%d", &x, &y) && !(x == 0 && y == 0)) {
            sumx += x;
            sumy += y;
        }
        sumx = -sumx;
        sumy = -sumy;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                printf("%d ", matrix[(n + (i - sumy)%n)%n][(m + (j + sumx)%m)%m]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
