#include <stdio.h>
#include <stdlib.h>

int i, n, t, tmp, curr, tests = 1, low, high;

int main(void) {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &curr);
        low = 0, high = 0;
        for(i = 1; i < n; i++) {
            scanf("%d", &tmp);
            if(tmp > curr) low++; else if(tmp < curr) high++;
            curr = tmp;
        }
        printf("Case %d: %d %d\n", tests++, low, high);
    }
    return 0;
}
