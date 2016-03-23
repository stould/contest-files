#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, x, y, n, m, k;

int main(void) {
    while(scanf("%d", &k) == 1 && k != 0) {
        scanf("%d%d", &n, &m);
        for(i = 0; i < k; i++) {
            scanf("%d%d", &x, &y);
            if(x < n && y > m) {
                printf("NO\n");
            } else if(x < n && y < m) {
                printf("SO\n");
            } else if(x > n && y > m) {
                printf("NE\n");
            } else if(x > n && y < m) {
                printf("SE\n");
            } else {
                printf("divisa\n");
            }
        }
    }
    return 0;
}
