#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

int N, S, ans, dp[100][100][100];

void rec(int base, int x, int used) {
    if(x == S && used == N) {
        if(!dp[base][x][used]) {
            dp[base][x][used] = 1;
            ans += 1;
        }
        return;
    }
    dp[base][x][used] = 1;
    if(x > S) return;
    for(int i = base; i <= 9; i++) {
        rec(i + 1, x + i, used + 1);
    }
}

int main(void) {
    while(1) {
        scanf("%d%d", &N, &S);
        if(N == 0 && S == 0) break;
        ans = 0;
        memset(dp, 0, sizeof(dp));
        rec(0, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
