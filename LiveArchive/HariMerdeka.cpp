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

const int MAXN = 9905;
const int INF = INT_MAX / 5;

int test, N, M, B;
int C[30], P[110];
string S[110];
char L[30];
int dp[MAXN][210];
int profit[MAXN];
int T[MAXN], term[MAXN], sig[MAXN][30], cnt;

void add(string& arg, int id) {
    int x = 0, n = (int) arg.size();

    for (int i = 0; i < n; i++){
        int c = (int) arg[i] - 'A';
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


int func(int pos, int bd) {
    if (bd < 0) {
        return -INF;
    } else {
        int& ans = dp[pos][bd];

        if (ans == -1) {
            ans = 0;
            
            for (int i = 0; i < N; i++) {
                if (bd - C[i] >= 0) {
                    int nd = pos;
                    int gain = 0;
                    
                    while (sig[nd][L[i] - 'A'] == 0) {
                        nd = T[nd];
                        if (nd == 0) {
                            break;
                        }
                    }

                    nd = sig[nd][L[i] - 'A'];
                    
                    if (term[nd]) {
                        gain += profit[nd];                        
                    }

                    chmax(ans, gain + func(nd, bd - C[i]));
                }
            }
        }
        
        return ans;
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> test;

    for (int t = 1; t <= test; t++) {
        cin >> N >> M >> B;

        cnt = 1;
        
        for (int i = 0; i < N; i++) {
            cin >> L[i] >> C[i];
        }

        for (int i = 0; i < M; i++) {
            cin >> S[i] >> P[i];
            add(S[i], i);
        }

        aho();

        memset(dp, -1, sizeof(dp));
        
        cout << "Case #" << t << ": " << func(0, B) << endl;
        
        memset(sig, 0, sizeof(sig));
        memset(profit, 0, sizeof(profit));    
    }
    return 0;
}
