#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef long long ll;

ll i, j, k, n, m, s, g, d;
ll matrix[260][260];

ll min(ll a, ll b) { return a < b ? a : b; }

int main(void) {
    scanf("%lld", &n);
    memset(matrix, 0, sizeof(matrix));
    for(i = 0; i < n; i++) for(j = 0; j < n; j++) scanf("%lld", &matrix[i][j]);
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    scanf("%lld", &m);
    for( ; m-- > 0; ) {
        scanf("%lld%lld%lld", &s, &g, &d);
        printf("%lld %lld\n", matrix[s][g] + matrix[g][d], matrix[s][g] + matrix[g][d] - matrix[s][d]);
    }
    return 0;
}
