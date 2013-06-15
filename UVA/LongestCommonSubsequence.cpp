#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

string a, b;
int dp[1010][1010];

int main(void) {
    while(getline(cin, a)) {
        getline(cin, b);
        int n = a.size();
        int m = b.size();

         for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
               if(i == 0 || j == 0) {
                    dp[i][j] = 0;
               } else if(a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}
