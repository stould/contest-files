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

const int MAXN = 330;
const Int INF = 100100101010000LL;

int T, N, M;
int C[MAXN][MAXN];
Int dp[MAXN][MAXN];

Int func(int d, int has) {
    if (d == N) {
        return has == 0 ? 0 : INF;
    } else if (has < 0) {
        return INF;
    } else {
        Int& ans = dp[d][has];

        if (ans == -1) {
            ans = func(d + 1, has - 1);

            Int sum = 0;
            
            for (int i = 0; i < M; i++) {
                sum += C[d][i];
                
                chmin(ans, (i + 1) * (i + 1) + sum + func(d + 1, has + i));
            }
               
        }
        
        return ans;
    }
}
int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> C[i][j];
            }
            sort(C[i], C[i] + M);
        }

        cout << "Case #" << t << ": ";

        memset(dp, -1, sizeof(dp));

        cout << func(0, 0) << endl;
    }
    
    return 0;
}
