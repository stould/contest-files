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
typedef unsigned uint;

const int MAXN = 1010;
const Int MOD = 1000000007LL;

int K;
Int bin[MAXN][MAXN];
Int dp[MAXN][MAXN];

Int func(int pos, int used) {
    if (used == 0LL || pos == 1LL) {
        return 1;
    } else {
        Int& ans = dp[pos][used];
        
        if (ans == -1) {
            ans = func(pos - 1, used) + func(pos, used - 1);
            ans = ((ans % MOD) + MOD) % MOD;                
        }
        
        return ans;
    }
}

int main(void) {
    cin >> K;
    
    vector<int> C(K);
    
    for (int i = 0; i < K; i++) {
        cin >> C[i];
    }

    memset(dp, -1, sizeof(dp));
    
    Int ans = 1LL, base = 1;
    
    for (int i = 0; i < K; i++) {
        ans *= func(base, C[i]-1);
        ans = ((ans % MOD) + MOD) % MOD;
        base += C[i];
    }

    cout << ans % MOD << "\n";
    
    return 0;
}
