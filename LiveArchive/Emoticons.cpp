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

const int MAXN = 1250;
const int MAX_ALPHA = 256;
const int INF = INT_MAX / 5;

int N, M;
string S, EM[MAXN];

int dp[110][MAXN];

int T[MAXN], term[MAXN], sig[MAXN][MAX_ALPHA], cnt;

void add(string arg) {
    int x = 0, n = (int) arg.size();
    
    for (int i = 0; i < n; i++){
        int c = arg[i];
        if (sig[x][c] == 0) {
            term[cnt] = 0;
            sig[x][c] = cnt++;
        }
        x = sig[x][c];
    }
    term[x] = 1;
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
            while (sig[v][i] == 0 && v != 0) v = T[v];
            int y = sig[v][i];
            
            Q.push(x);
            T[x] = y;
            term[x] |= term[y];
        }
    }
}

int func(int pos, int trie_pos) {
    if (term[trie_pos]) return INF;
    if (pos == (int) S.size()) {
        return 0;
    } else {
        int& ans = dp[pos][trie_pos];

        if (ans == -1) {
            ans = INF;

            int next_node = trie_pos;

            while (next_node != 0 && sig[next_node][(int) S[pos]] == 0) {
                next_node = T[next_node];
            }

            next_node = sig[next_node][(int) S[pos]];
            
            if (!term[next_node]) {
                ans = func(pos + 1, next_node);
            }
            ans = min(ans, 1 + func(pos + 1, 0));        
        }

        return ans;
    }
}

int main(void) {
    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;

        cnt = 1;
        memset(sig, 0, sizeof(sig));
        
        for (int i = 0; i < N; i++) {
            cin >> EM[i];
            reverse(EM[i].begin(), EM[i].end());
            add(EM[i]);
        }


        aho();
        
        Int ans = 0;

        getline(cin, S);
        
        for (int i = 0; i < M; i++) {
            getline(cin, S);
            reverse(S.begin(), S.end());                    
            memset(dp, -1, sizeof(dp));

            ans += func(0, 0);
        }

        cout << ans << endl;
    }
    
    return 0;
}
