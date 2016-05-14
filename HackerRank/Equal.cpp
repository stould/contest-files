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

using namespace std;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 500010;

int T, N;
int P[MAXN];
int dp[MAXN], best[MAXN];

int main(void) {
    cin >> T;

    dp[0] = 0;

    for (int i = 1; i < MAXN; i++) {
        dp[i] = dp[i - 1] + 1;

        if (i - 2 >= 0) {
            chmin(dp[i], dp[i - 2] + 1);
        }
        if (i - 5 >= 0) {
            chmin(dp[i], dp[i - 5] + 1);
        }
    }

    for (int i = 0; i < MAXN; i++) {
        best[i] = i;
        
        for (int j = 0; j < 10; j++) {
            if (i + j < MAXN) {
                if (dp[i + j] < dp[i]) {
                    // best[i] = j;
                    //dp[i] = dp[i + j];
                }
            }
        }
    }
    
    for (int t = 1; t <= T; t++) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }

        sort(P, P + N);

        int ans = 0;
        int acc = 0;
        
        for (int i = 1; i < N; i++) {
            P[i] += acc;
            
            int df = P[i] - P[i - 1];            
            
            ans += dp[df];

            //cout << P[i] << " " << df << " " << dp[df] << "\n";

            acc += df;
        }
        
        cout << ans << "\n";        
    }
    return 0;
}
