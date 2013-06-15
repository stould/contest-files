#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>

using namespace std;

int i, j, k, n, xi, xf, yi, yf, mem[110][110];

int main(void) {
    scanf("%d", &n);
    for(i = 1; i <= 100; i++) {
        for(j = 1; j <= 100; j++) {
            mem[i][j] = 0;
        }
    }
    set<pair<int, int> > s;
    for(i = 0; i < n; i++) {
        scanf("%d%d%d%d", &xi, &xf, &yi, &yf);
        for(j = xi; j < xf; j++) {
            for(k = yi; k < yf; k++) {
                s.insert(make_pair(j, k));
            }
        }
    }
    printf("%d\n", s.size());
    return 0;
}
