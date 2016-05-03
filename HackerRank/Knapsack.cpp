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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 2020;
const int INF = 100100100;

int T, N, K;
int P[MAXN];
int dp[MAXN][MAXN];

int func(int pos, int sum) {
    if (sum > K) {
        return -INF;
    } else if (pos == N) {
        return sum;
    } else {
        int& ans = dp[pos][sum];

        if (ans == -1) {
            ans = 0;

            chmax(ans, func(pos + 1, sum));
            for (int i = 1; sum + i * P[pos] <= K; i++) {
                chmax(ans, func(pos + 1, sum + i * P[pos]));            
            }            
        }
        
        return ans;
    }
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> K;

        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }

        memset(dp, -1, sizeof(dp));

        cout << func(0, 0) << endl;
    }
    return 0;
}
