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

const int MAXN = 10010;
const int MAX_AHO = 1000004;
const int MAX_ALPHA = 26;

int N;
string S[MAXN];
int T[MAX_AHO], sig[MAX_AHO][MAX_ALPHA], cnt;
int term[MAX_AHO];
int dp[MAX_AHO];
vector<int> ind[MAX_AHO];
vector<int> G[MAXN];
char buff[MAXN];

void add(string& arg, int id) {
    int x = 0, n = (int) arg.size();

    for (int i = 0; i < n; i++){
        int c = (int) arg[i] - 'a';
        if (sig[x][c] == 0) {
            sig[x][c] = cnt++;
        }
        x = sig[x][c];
    }

    ind[x].push_back(id);
}

void aho() {
    queue <int> q;

    for (int i = 0; i < MAX_ALPHA; i++){
        int v = sig[0][i];

        if (v > 0) {
            q.push(v);
            T[v] = 0;
        }
    }
    
    while (!q.empty()){
        int u = q.front();
        q.pop();

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
            q.push(x);
            
            T[x] = y;
            term[x] |= term[y];
            
            ind[x].insert(ind[x].end(), ind[y].begin(), ind[y].end());
        }
    }
}

int func(int pos) {
    int& ans = dp[pos];

    if (ans == -1) {
        ans = 0;

        for (int i = 0; i < (int) G[pos].size(); i++) {
            int u = G[pos][i];

            chmax(ans, 1 + func(u));
        }
    }

    return ans;
}

int main(void) {
    for ( ; scanf("%d", &N) == 1 && N > 0; ) {
        cnt = 1;
        memset(sig, 0, sizeof(sig));
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < MAX_AHO; i++) {
            ind[i].clear();
            if (i < MAXN) {
                G[i].clear();
            }
        }
        
        for (int i = 1; i <= N; i++) {
            scanf("%s", buff);
            S[i] = string(buff);
            add(S[i], i);
        }

          aho();
        
        for (int i = 1; i <= N; i++) {
            int state = 0;

            for (int j = 0; j < (int) S[i].size(); j++) {
                while (sig[state][S[i][j] - 'a'] == 0) {
                    if (state == 0) {
                        break;
                    }
                    state = T[state];                    
                }

                state = sig[state][S[i][j] - 'a'];

                for (int k = 0; k < (int) ind[state].size(); k++) {
                    if (i != ind[state][k]) {
                        G[i].push_back(ind[state][k]);
                    }
                }
            }
        }
        
        for (int i = 0; i < MAXN; i++) {
            G[0].push_back(i);
        }     
        
        cout << func(0) << "\n";
    }
    return 0;
}
