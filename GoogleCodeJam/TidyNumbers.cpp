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

int T, L;
uInt N;
string S;
int memo[19][11][2];
Int dp[19][11][2];

Int func(int pos, int last, int matching) {
    if (pos == L) {
        return 1;
    } else {
        if (memo[pos][last][matching] == -1) {
            Int& ans = dp[pos][last][matching];

            ans = 0;
            
            for (int i = last; i <= 9; i++) {
                int digit_now = S[pos] - '0';                
                
                if (matching && i > digit_now) continue;
                
                ans += func(pos + 1, i, matching && i == digit_now);
            }            
        }
        
        return dp[pos][last][matching];
    }
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        Int l = 1, h = N, m = N;
        Int ans = 1;
        
        memset(memo, -1, sizeof(memo));
        S = to_string(N);
        L = (int) S.size();

        Int counted = func(0, 0, 1) - 1;
        
        while (l <= h) {
            m = l + (h - l) / 2;
            
            memset(memo, -1, sizeof(memo));
            
            S = to_string(m);
            L = (int) S.size();
            
            Int now = func(0, 0, 1) - 1;

            if (now < counted) {
                l = m + 1;
            } else {
                ans = m;
                h = m - 1;
            }
        }
        cout << "Case #" << t << ": ";
        cout << ans << "\n";
    }
    return 0;
}
