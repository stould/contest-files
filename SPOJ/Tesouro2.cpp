#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int d, i, j, v[110], sub[1110100], t = 1, x, y;

bool subsetSum(int n, int g) {
    for(j = 0; j <= g; j++) sub[j] = 0;
    sub[0] = 1;
    for(j = 0; j < n; j++) if(v[j] != g) {
        for(int k = g; k >= v[j]; k--) {
            sub[k] |= sub[k - v[j]];
        }
    }
    return sub[g];
}

int main(void) {
    while(~scanf("%d%d%d", &x, &y, &d) &&  x > 0 && y > 0 && d > 0) {
        int sum = 0;
        for(i = 0; i < d; i++) {
            scanf("%d", &v[i]);
            sum += v[i];
        }
        printf("Teste %d\n", t++);
        int poss = (int) (fabs(x - y) + sum) % 2 == 0;
        if(poss && subsetSum(d, (fabs(x - y) + sum)/2)) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }
    return 0;
}
