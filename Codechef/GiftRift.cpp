#include <stdlib.h>
#include <stdio.h>

const int INF = 100100000;
int i, j, k, m, index, r, c, v[110][110], low_row[110];

int main(void) {
    scanf("%d%d", &r, &c);
    for(i = 0; i < r; i++) {
        m = INF;
        for(j = 0; j < c; j++) {
            scanf("%d", &v[i][j]);
            if(v[i][j] < m) {
                m = v[i][j];
            }
        }
        low_row[i] = m;
    }
    int ans = -1;
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            if(v[i][j] == low_row[i]) {
                m = -1;
                for(k = 0; k < r; k++) {
                    if(v[k][j] > m) {
                        m = v[k][j];
                    }
                }
                if(m == low_row[i]) {
                    ans = m;
                    goto end;
                }
            }
        }
    } end:;
    if(ans == -1) {
        printf("GUESS\n");
    } else {
        printf("%d\n", ans);
    }
    return 0;
}
