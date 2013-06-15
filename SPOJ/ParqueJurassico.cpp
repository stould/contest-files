#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int i, j, n, m, teste = 1, dp[110][110];
char a[110], b[110];

int min(int a, int b) {
    return a < b ? a : b;
}

void print(int i, int j) {
    int k;
    if(i == 0) {
        for(k = 0; k < j; k++)
            printf("%c",a[k]);
        return;
    }
    if(j == 0) {
        for(k=0; k<i; k++)
            printf("%c",b[k]);
        return;
    }
    if(a[j-1] == b[i-1] ) {
        print(i - 1,j - 1);
        printf("%c",a[j-1]);
    } else if(dp[i][j] == dp[i][j-1]+1) {
        print(i, j - 1);
        printf("%c",a[j-1]);
    } else {
        print(i-1,j);
        printf("%c",b[i-1]);
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    while(1) {
        scanf("%s", a); n = strlen(a);
        scanf("%s", b); m = strlen(b);
        if(n == 1 && a[0] == '#') break;
        dp[0][0] = 0;
        for(i = 0; i <= n; i++) {
            for(j = 0; j <= m; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if(a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
                }
            }
        }
        printf("Teste %d\n", teste++);
        print(n, m);
        printf("\n\n");
    }
    return 0;
}
