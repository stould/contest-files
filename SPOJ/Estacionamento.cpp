#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, j, k, c, n, q, p, amount;
char state;
int mem[1010];

int main(void) {
    for(; ~scanf("%d%d", &c, &n); ) {
        memset(mem, 0, sizeof(mem));
        amount = 0;
        for(i = 0; i < n; i++) {
            scanf(" %c", &state);
            if(state == 'C') {
                scanf("%d%d", &p, &q);
                for(j = 0; j < c; j++) {
                    if(mem[j] == 0 && j + q <= c) {
                        k = j;
                        for(;k < j + q; k++) {
                            if(mem[k] != 0) break;
                        }
                        if(k == j + q) {
                            amount += 10;
                            for(k = j; k < j + q; k++) {
                                mem[k] = p;
                            }
                            break;
                        }
                    }
                }
            } else {
                scanf("%d", &p);
                for(j = 0; j < c; j++) {
                    if(mem[j] == p) mem[j] = 0;
                }
            }
        }
        printf("%d\n", amount);
    }
    return 0;
}

