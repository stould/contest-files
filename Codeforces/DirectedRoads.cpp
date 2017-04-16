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

const int MAXN = 200005;
const Int MOD = 10000000007LL;

int N;
int P[MAXN];
int G[MAXN];
int level[MAXN];
int vis[MAXN];

Int modPow(Int a, Int n, Int mod) {
    Int res = 1;
    while (n) {
        if (n & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        n /= 2;
    }
    return res % MOD;
}


int main(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        G[i] = P[i];
    }

    Int ans = 1LL;
    int spare = N;
    
    for (int i = 1; i <= N; i++) {
        if (level[i] == 0) {
            int s = i;
            int len = 0;
            
            while (vis[s] == 0) {
                vis[s] = 1;
                len += 1;
                s = G[s];
                if (vis[s] == i) {
                    int len = level[pr] + 1 - level[s];

                    ans *= (modPow(2, len, MOD) - 2);
                    spare -= len;
                    break;
                } else if (vis[s] > 0) {
                    break;
                }
            }
        }
    }

    ans *= (modPow(2, spare, MOD) % MOD);

    ans %= MOD;
    ans = ((ans % MOD) + MOD) % MOD;

    cout << ans % MOD << "\n";
    return 0;
}
