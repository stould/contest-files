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

const int MAXN = 51;

int N;
int A[3][MAXN];
int B[MAXN];
int dp[3][MAXN];
int val[MAXN];

int main(void) {
    cin >> N;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N - 1; j++) {
            cin >> A[i][j];

            dp[i][j] = A[i][j];

            if (j > 0) {
                dp[i][j] += dp[i][j - 1];
            }
        }
        dp[i][N - 1] = dp[i][N - 2];
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    int ans = INT_MAX;

    for (int i = 0; i < N; i++) {
        int curr = 0;

        if (i - 1 >= 0) {
            curr += dp[0][i - 1];
        }

        curr += B[i];
        curr += (dp[1][N - 2]);

        if (i - 1 >= 0) {
            curr -= dp[1][i - 1];
        }
        
        val[i] = curr;
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ans = min(ans, val[i] + val[j]);
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
