#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int c, d, i, j, k, n, s, t = 1, graph[25][25];

int main(void) {
    while(scanf("%d", &n) && n > 0) {
        memset(graph, 0, sizeof(graph));
        for (i=0; i<n; i++) {
            while(scanf("%d",&d)==1 && d) {
                d--;
                graph[i][d] = 1;
                graph[d][i] = 1;
            }
        }
        int mx = 0;
        for(i = 0; i < (1 << (n)); i++) {
            int valid = 1;
            int amount = 0;
            for(j = 0; j < n; j++) if(1 & (i >> j)) {
                amount += 1;
                for(k = 0; k < n; k++) if(1 & (i >> k)) if(j != k) {
                    if(amount <= 1) break;
                    if(graph[j][k] == 1) {
                        valid = 0;
                    }
                }
            }
            if(valid && amount > mx) {
                mx = amount;
            }
        }
        printf("Teste %d\n%d\n\n", t++, mx);
    }
    return 0;
}
