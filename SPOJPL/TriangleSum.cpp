#include <iostream>

using namespace std;

const int MAXN = 110;
const int INF = 1000000000;
int t, n, dp[MAXN][MAXN], maze[MAXN][MAXN];

int main(void) {
    cin >> t;
    while(t--) {
        cin >> n; int x = 0;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j < x; j++) {
                cin >> maze[i][j];
                dp[i][j] = -INF;
            }
            x++;
        }
        dp[0][0] = maze[0][0]; x = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < x; j++) {
                int mx = dp[i - 1][x];
                if(x >= 0) {
                    mx = max(mx, mx + maze[i - 1][x]);
                }
                if(x - 1 >= 0) {
                    mx = max(mx, mx + maze[i - 1][x - 1]);
                }
                dp[i][x] = max(dp[i][x], mx);
            }
            x++;
        }
        int m = 0;
        for(int i = 0; i < n; i++) {
            m = max(m, dp[n][i]);
        }
        cout << m << endl;
    }
    return 0;
}
