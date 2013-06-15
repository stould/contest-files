#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int i, b, c, d, n, v, reserve[50], ct, total;

int main(void) {
    while(scanf("%d%d", &b, &n) == 2 && !(n == 0 && b == 0)) {
        for(i = 1; i <= b; i++) {
            scanf("%d", &reserve[i]);
        }
        for(i = 0; i < n; i++) {
            scanf("%d%d%d", &d, &c, &v);
            reserve[d] -= v;
            reserve[c] += v;
        }
        bool poss = true;
        for(i = 1; i <= b; i++) if(reserve[i] < 0) poss = false;
        if(poss) {
            puts("S");
        } else {
            puts("N");
        }
    }
    return 0;
}
