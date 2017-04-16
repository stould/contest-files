#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int T;
long long N, K, MOD;
long long P[MAXN];

long long modPow(long long base, long long ex, long long mod) {
    long long ans = 1;
    
    while (ex > 0) {
        if (ex % 2 == 1) {
            ans = (ans * base) % mod;
        }
        ex /= 2;
        base = (base * base) % mod;
    }
    
    ans %= mod;
    ans += mod;
    ans %= mod;
    
    return ans;
}

int main() {
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        cin >> N >> K >> MOD;
        
        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }
        
        long long ans = 0LL;
        
        for (int i = 0; i < N; i++) {
            ans += (P[i] % MOD) * (K % MOD) * modPow(N, K - 1, MOD);
            ans %= MOD;
        }
        
        ans %= MOD;
        ans += MOD;
        ans %= MOD;
        
        cout << "Case " << t << ": " << ans << "\n";
    }
    return 0;
}
