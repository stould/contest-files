#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m, l, r, best, minimal, d[1010];

int max(int a, int b) { return a > b ? a : b; }

int main(void) {
    scanf("%d", &n);
    best = 0, minimal = -100000000;
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        l = 0, r = 0;
        for(int j = 0; j < m; j++) {
            scanf("%d", &d[j]);
            if(j > 0) {
                if(d[j - 1] > d[j]) {
                    l += d[j] - d[j - 1];
                } else if(d[j - 1] < d[j]) {
                    r += d[j - 1] - d[j];
                }
            }
        }
        if(l > minimal) {
            minimal = l;
            best = i + 1;
        }
        if(r > minimal) {
            minimal = r;
            best = i + 1;
        }
    }
    printf("%d\n", best);
    return 0;
}
