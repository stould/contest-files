#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int n, dp[100][100] = {0};
string a;

int main(void) {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        int start = a[0] - 'a';
        int end = a[a.size() - 1] - 'a';

        for(int j = 0; j < 26; j++) {
            if(dp[j][start] > 0) {
                dp[j][end] = max(dp[j][end], dp[j][start] + (int) a.size());
            }
        }
        dp[start][end] = max(dp[start][end], (int) a.size());
    }
    int ans = 0;
    for(int i = 0; i < 26; i++) ans = max(ans, dp[i][i]);
    cout << ans << endl;
    return 0;
}
