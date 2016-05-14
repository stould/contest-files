#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int INF = 10000000;
int x, y, u, v, n, test = 1;

int main(void) {
    while(scanf("%d", &n) == 1 && n != 0) {
        int x1 = -INF, y1 = INF, x2 = INF, y2 = -INF;
        for(int i = 0; i < n; i++) {
            scanf("%d%d%d%d", &x, &y, &u, &v);
            if(x > x1) x1 = x;
            if(y < y1) y1 = y;
            if(u < x2) x2 = u;
            if(v > y2) y2 = v;
        }
        printf("Teste %d\n", test++);
        if(x2 < x1 || y1 < y2) {
            printf("nenhum\n");
        } else {
            printf("%d %d %d %d\n", x1, y1, x2, y2);
        }
        printf("\n");
    }
    return 0;
}
