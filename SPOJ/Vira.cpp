#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, j, n, sum, mem[110], dp[110][110];
char c;

//DP - State
//DP[i][j] = number of black piecies if we remove piece 'j'

int min(int a, int b) { return a < b ? a: b; }
int max(int a, int b) { return a > b ? a: b; }

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d", &n); sum = 0;
    for(i = 0; i < n; i++) {
        scanf("%c", &c);
        if(c == 'B') {
            mem[i] = 0;
        } else {
            mem[i] = 1;
            sum++;
        }
    }
    for(i = 0; i < n; i++) dp[0][i] = sum;
    for(i = 1; i < n; i++) {
        for(j = 0; j < n; j++) {
            int sub = 0;
            if(mem[j] == 1) {
                if(i > 0 || i != n - 1) {
                    sub += 2;
                } else {
                    sub += 1;
                }
            } else {
                if(i > 0 || i != n - 1) {
                    sub -= 2;
                } else {
                    sub -= 1;
                }
            }
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j] - sub);
        }
    }
    int ans = 0;
    for(i = 0; i < n; i++) {
        printf("%d\n", dp[n-1][i]);
    }
    return 0;
}
