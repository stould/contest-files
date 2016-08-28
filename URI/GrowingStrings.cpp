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

const uInt MOD = 1000000007ULL;
const uInt BASE = 19ULL;

const int MAXN  = 10004;
const int MAXL = 1010;

int N;
char S[MAXN][MAXL];
int len[MAXN], indeg[MAXN];
uInt pw[MAXL], inv[MAXL];
uInt hs[MAXN][MAXL];
int dp[MAXN];

vector<int> graph[MAXN];

uInt modPow(uInt a, uInt n, uInt mod) {
    uInt res = 1ULL;
	
    while (n > 0ULL) {
        if (n & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
    }
	
    return res;
}

pair<uInt, pair<uInt, uInt> > extendedEuclid(uInt a, uInt b) {
    uInt x = 1, y = 0;
    uInt xLast = 0, yLast = 1;
    uInt q, r, m, n;
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}
 
uInt modInverse(uInt a, uInt m) {
    return modPow(a, m - 2, m);
    //return (extendedEuclid(a,m).second.first + m) % m;
}

uInt get_hash(int id, int l, int h) {
    uInt ans = hs[id][h];

    if (l > 0) {
        ans -= hs[id][l - 1];
        ans = (ans + MOD) % MOD;
        ans = (ans * inv[l]) % MOD;
    }

    return ans % MOD;
}

//check whether S[y] is inside S[x]
bool seen(int x, int y) {
    uInt base_hash = get_hash(y, 0, len[y] - 1);
	
    for (int i = 0; i + len[y] <= len[x]; i++) {
        if (base_hash == get_hash(x, i, i + len[y] - 1)) {
            return true;
        }
    }

    return false;
}

int func(int id) {
    if (graph[id].size() == 0) {
        return 1;
    } else {
        int& ans = dp[id];
		
        if (ans == -1) {
            ans = 0;

            for (int i = 0; i < (int) graph[id].size(); i++) {
                chmax(ans, 1 + func(graph[id][i]));
            }
        }

        return ans;
    }
}

int main(void) {
    pw[0] = 1;

    for (int i = 1; i < MAXL; i++) {
        pw[i] = (pw[i - 1] * BASE) % MOD;
        inv[i] = modInverse(pw[i], MOD);
    }
	
    for ( ; scanf("%d", &N) && N != 0; ) {
        for (int i = 0; i < N; i++) {
            graph[i].clear();
            indeg[i] = 0;
        }
		
        for (int i = 0; i < N; i++) {
            scanf("%s", S[i]);

            len[i] = strlen(S[i]);
			
            for (int j = 0; j < len[i]; j++) {
                hs[i][j] = (pw[j] * (S[i][j] - 'a' + 1));
                if (j > 0) {
                    hs[i][j] += hs[i][j - 1];
                }
                hs[i][j] %= MOD;

                if (hs[i][j] < 0) {
                    hs[i][j] += MOD;
                }
            }
            for (int j = 0; j < i; j++) {
                if (len[i] < len[j]) {
                    if (seen(j, i)) {
                        graph[i].push_back(j);
                    }
                }
                if (len[i] > len[j]) {
                    if (seen(i, j)) {
                        graph[j].push_back(i);
                        indeg[i]++;
                    }
                }
            }
        }

        memset(dp, -1, sizeof(dp));

        int ans = 0;

        for (int i = 0; i < N; i++) {
            if (indeg[i] != 0) continue;
            chmax(ans, func(i));
        }
        printf("%d\n", ans);
    }
	
    return 0;
}
