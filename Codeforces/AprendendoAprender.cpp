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

const int MAXN = 6 * 250 + 1;
const int MAX_ALPHA = 26;
const Int INF = 1001001010000100LL;
const Int MOD = 1e9 + 9;

int QR, K;
string S;

int T[MAXN], term[MAXN], sig[MAXN][MAX_ALPHA], cnt = 1;

void add(string& arg, int id) {
    int x = 0, n = (int) arg.size();
    
    for (int i = 0; i < n; i++){
        int c = arg[i] - 'a';
        if (sig[x][c] == 0) {
            term[cnt] = 0;
            sig[x][c] = cnt++;
        }
        x = sig[x][c];
    }
    
    term[x] = 1 << id;
}


void aho() {
    queue<int> Q;
    for (int i = 0; i < MAX_ALPHA; i++){
        int v = sig[0][i];

        if (v) {
            Q.push (v);
            T[v] = 0;
        }
    }
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        
        for (int i = 0; i < MAX_ALPHA; i++){
            int x = sig[u][i];

            if (x == 0) {
                continue;
            }

            int v = T[u];            
            while (sig[v][i] == 0 && v != 0) {
                v = T[v];
            }
            int y = sig[v][i];
            
            Q.push(x);
            T[x] = y;
            term[x] |= term[y];
        }
    }
}

Int dp[51][MAXN][1 << 6];
int memo[51][MAXN][1 << 6];

Int func(int pos, int trie_pos, int mask) {
    if (pos == 0) {
        return __builtin_popcount(mask) <= K ? 1LL : 0LL;
    } else {
        Int& ans = dp[pos][trie_pos][mask];

        if (memo[pos][trie_pos][mask] == false) {
            memo[pos][trie_pos][mask] = true;

            ans = 0;

            for (int i = 0; i < MAX_ALPHA; i++) {
                int next_pos = trie_pos;
                int next_mask = mask;
                
                while (next_pos != 0 && sig[next_pos][i] == 0) {
                    next_pos = T[next_pos];
                }

                next_pos = sig[next_pos][i];
                next_mask |= term[next_pos];                
                
                ans = ((ans % MOD) + (func(pos - 1, next_pos, next_mask) % MOD)) % MOD;
                ans %= MOD;
            }
        }

        ans %= MOD;
        ans += MOD;
        ans %= MOD;

        return ans % MOD;
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> QR >> K;

    vector<string> batch;
    
    while (QR--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            cin >> S;
            
            batch.push_back(S);

            memset(sig, 0, sizeof(sig));
            memset(term, 0, sizeof(term));
            memset(T, 0, sizeof(T));
            
            cnt = 1;

            for (int i = 0; i < (int) batch.size(); i++) {
                add(batch[i], i);
            }
            
            aho();

            memset(memo, false, sizeof(memo));
        } else {
            int len;            
            cin >> len;
            
            cout << func(len, 0, 0) % MOD << "\n";
        }
    }
    return 0;
}
