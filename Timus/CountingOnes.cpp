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

Int X;
Int dp[20][15][20][2];
string S;

Int func(int pos, int last, int used, bool pref) {
    if (pos == (int) S.size()) {
        return used;
    } else {
        Int& ans = dp[pos][last][used][pref];

        if (ans == -1) {
            ans = 0;

            for (int i = 0; i <= 9; i++) {
                if (pref && i > S[pos] - '0') continue;
                ans += func(pos + 1, 1, used + (i == 1 ? 1 : 0), pref && S[pos] - '0' == i);
            }
        }
        
        return ans;
    }
}


int main(void) {
    cin >> X;
    
    Int l = 0, h = 1000000000000000000LL, m;
    Int ans = -1;
    
    while (l <= h) {
        m = l + (h - l) / 2;

        memset(dp, -1, sizeof(dp));
        S = to_string(m);
        
        Int now = func(0, 10, 0, 1);
        
        if (now == X) {
            ans = m;
            h = m - 1;
        } else if (now > X) {
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    if (ans != -1) {
        cout << ans << endl;
    } else {
        cout << "Petr lies" << endl;
    }
    
    return 0;
}
