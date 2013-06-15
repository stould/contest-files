#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, j, n, test = 1;
char s[2020];

bool is(int a, int b) {
    for(; a < b; a++, b--) {
        if(s[a] != s[b]) return false;
    }
    return true;
}


int main(void) {
    freopen("i.in", "r", stdin);
    while(scanf("%d", &n) == 1 && n != 0) {
        scanf("%s", s);
        int m = 0;
        for(i = 0; i < n; i++) {
            int has = -1;
            for(j = i; j < n; j++) {
                if(is(i, j)) {
                    has = j;
                }
            }
      //      printf("%d %d\n", i, has);
            i = has;
            m++;
        }
        printf("Teste %d\n%d\n\n", test++, m);
    }
    return 0;
}
