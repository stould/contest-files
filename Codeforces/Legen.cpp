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

const int MAXN = 205;
const int MAX_TRIE = 210;
const int MAX_K = 120005;

int N;
Int K;
Int P[MAXN];
string S[MAXN];
Int dp[MAX_K][MAX_TRIE];
Int profit[MAX_TRIE];
int T[MAX_TRIE], term[MAX_TRIE], sig[MAX_TRIE][30], cnt;

void add(string& arg, int id) {
    int x = 0, n = (int) arg.size();

    for (int i = 0; i < n; i++){
        int c = (int) arg[i] - 'a';
        
        if (sig[x][c] == 0) {
            term[cnt] = 0;
            sig[x][c] = cnt++;
        }
        x = sig[x][c];
    }
    
    term[x] = 1;
    profit[x] += P[id];
}

void aho (){
    queue <int> Q;
    for (int i = 0; i < 30; i++){
        int v = sig[0][i];
        if (v) Q.push (v), T[v] = 0;
    }
    while (!Q.empty()){
        int u = Q.front(); Q.pop();
        for (int i = 0; i < 30; i++){
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
            profit[x] += profit[y];
        }
    }
}


Int func(int len, int pos) {
    if (len <= 0) {
        return 0;
    } else {
        Int& ans = dp[len][pos];

        if (ans == -1LL) {
            ans = 0LL;
            
            for (int c = 0; c < 26; c++) {
                int nd = pos;
                Int gain = 0;
                
                while (sig[nd][c] == 0) {
                    nd = T[nd];
                    if (nd == 0) {
                        break;
                    }
                }

                nd = sig[nd][c];
                
                if (term[nd]) {
                    gain += profit[nd];                        
                }
                
                chmax(ans, gain + func(len - 1, nd));
            }
        }        
        
        return ans;
    }
}

int main(void) {
    cin >> N >> K;

    cnt = 1;
    
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        add(S[i], i);
    }

    memset(dp, -1, sizeof(dp));    
    aho();

    Int ans = 0LL;
    int ub = min(K, (Int) MAX_K - 1);
    
    for (int i = 1; i <= ub; i++) {
        Int ia = func(i, 0);
        Int mul = K / i;
        Int mod = K % i; 

        ans = max(ans, func(i, 0) * mul + func(mod, 0));                    
    }
    
    cout << ans << "\n";
    
    return 0;
}
