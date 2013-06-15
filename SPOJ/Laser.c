#include <stdlib.h>
#include <stdio.h>

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

int i, x, a, c, cut, ind, m[100010], help[100010];

int main(void) {
    while(~scanf("%d%d", &a, &c) && !(a == 0 && c == 0)) {
        REP(i, c) scanf("%d", &m[i]);
        cut = 0;
        for(x = a; x >= 0; x--) {
            ind = 0;
            REP(i, c) {
                if(m[i] < x) {
                    help[ind] = i;
                    if(ind - 1 < 0 || help[ind] != help[ind - 1] + 1) cut += 1;
                    ind += 1;
                }
            }
        }
        printf("%d\n", cut);
    }
    return 0;
}


