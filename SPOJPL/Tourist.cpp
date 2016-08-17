#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 110;
const int INF = 1001010;

int T;
int N, M;
char S[200][200];
int dp[MAXN][MAXN][MAXN][2];

int func(int row, int c1, int c2, int turn) {
    if (row >= N || c1 >= M || c2 >= M) {
        return -INF;
    } else if (S[row][c1] == '#' || S[row][c2] == '#') {
        return -INF;
    } else if (row == N - 1 && (c1 == M - 1 && c2 == M - 1)) {
        return 0;
    } else {
        int& ans = dp[row][c1][c2][turn];

        if (ans == -1) {
            ans = -INF;

            int cnt = 0;
            
            if (row + 1 < N) {
                cnt = 0;
                
                if (S[row + 1][c1] == '*') {
                    cnt += 1;
                }
                if (S[row + 1][c2] == '*') {
                    cnt += 1;
                }

                if (cnt == 2) {
                    cnt = 1;
                }
                chmax(ans, cnt + func(row + 1, c1, c2));
                
                cnt = 0;
                if (S[row + 1][c1 + 1] == '*') {
                    cnt += 1;
                }
                chmax(ans, cnt + func(row + 1, c1 + 1, c2));
            }
                
            if (c2 + 1 < M) {
                cnt = 0;
                if (S[row + 1][c2 + 1] == '*') {
                    cnt += 1;
                }
                chmax(ans, cnt + func(row + 1, c1, c2 + 1));                
            }
        }
        return ans;
    }
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> M >> N;

        memset(dp, -1, sizeof(dp));
        
        for (int i = 0; i < N; i++) {
            cin >> S[i];            
            cout << S[i] << endl;
        }

        int ans = func(0, 0, 0);

        if (S[0][0] == '*') {
            ans += 1;
        }

        cout << ans << endl;
    }
    return 0;
}
