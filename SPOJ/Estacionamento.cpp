#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, j, k, c, n, q, p, amount;
char state;
int mem[10010];

int main(void) {
    freopen("i.in", "r", stdin);
    for(; ~scanf("%d%d", &c, &n); ) {
        memset(mem, 0, sizeof(mem));
        amount = 0;
        for(i = 0; i < n; i++) {
            scanf(" %c", &state);
            if(state == 'C') {
                scanf("%d%d", &p, &q);
                for(j = 0; j <= c; j++) {
                    if(mem[j] == 0) {
                        k = j;
                        for(;k <= c && mem[k] == 0; k++) {
                            if(k - j == q) {
                                amount += 10;
                                for(int tmp = j; tmp <= k; tmp++) {
                                    mem[tmp] = p;
                                }
                                goto en;
                            }
                        }
                        j = k;
                    }
                }
            } else {
                scanf("%d", &p);
                for(j = 0; j <= c; j++) {
                    if(mem[j] == p) mem[j] = 0;
                }
            }
            en:;
        }
        printf("%d\n", amount);
    }
    return 0;
}
