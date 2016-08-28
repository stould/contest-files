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

int T;
int N, M;
int P[MAXN][MAXN];
Int dp[MAXN][MAXN];

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M;

        memset(dp, 0, sizeof(dp));
        memset(P, 0, sizeof(P));
        int ei = 0, ej = 0;
        int si = 0, sj = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                string arg;
                cin >> arg;

                if (arg == "P") {
                    si = i;
                    sj = j;
                } else if (arg == "E") {
                    ei = i;
                    ej = j;
                } else {
                    P[i][j] =  stoi(arg);
                }
            }
        }

        for (int i = si; i < N; i++) {
            for (int j = sj; j < M; j++) {
                if (i + 1 < N) {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + P[i + 1][j]);
                }
                if (j + 1 < M) {
                    dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + P[i][j + 1]);
                }
            }
        }

        cout << "Game Board #" << t << ": " << dp[ei][ej] << "\n";
    }
    return 0;
}
