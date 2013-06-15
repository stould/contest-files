#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

const int INF = 10000000;

int i, j, k, s, x[1010], y[1010], min_x, max_x, min_y, max_y, used[1010][1010], t = 1;

int main(void) {
    while(scanf("%d", &s) && s > 0) {
        memset(used, 0, sizeof(used));
        min_x = min_y = INF; max_x = max_y = -INF;
        for(i = 0; i < s; i++) {
            scanf("%d %d", &x[i], &y[i]);
            if(x[i] > max_x) max_x = x[i];
            if(x[i] < min_x) min_x = x[i];
            if(y[i] > max_y) max_y = y[i];
            if(y[i] < min_y) min_y = y[i];
        }
        int minimal = INF;
        int ans_x, ans_y;
        for(i = min_x; i <= max_x; i++) {
            for(j = min_y; j <= max_y; j++) {
                int dist = 0;
                for(k = 0; k < s; k++) {
                    dist += fabs(i - x[k]) + fabs(k - y[k]);
                }
                if(dist < minimal) {
                    minimal = dist;
                    ans_x = i; ans_y = j;
                }
            }
        }
        printf("Teste %d\n%d %d\n\n", (t++), ans_x, ans_y);
    }
    return 0;
}
