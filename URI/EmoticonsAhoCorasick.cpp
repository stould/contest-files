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

const int MAXN = 1250;
const int MAX_ALPHA = 260;
const int INF = INT_MAX / 5;

int N, M;
string EM[110];
string S;
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

int func(int pos, int tr) {
    if (term[tr]) {
        return INF;
    } else if (pos == (int) S.size()) {
        return 0;
    } else {
        int& ans = dp[pos][tr];

        if (ans == -1) {
            ans = INF;

            while (tr != 0 && sig[tr][(int) S[pos]] == 0) {
                tr = T[tr];
            }
            tr = sig[tr][(int) S[pos]];
            if (term[tr] == 0) {
                ans = func(pos + 1, tr);
            }
            
            ans = min(ans, 1 + func(pos + 1, 0));        
        }

        return ans;
    }
}

void rec(int pos, int tr) {
    if (term[tr]) {
        return;
    } else if (pos == (int) S.size()) {
        return;
    } else {        
        while (sig[tr][(int) S[pos]] == 0) {
            tr = T[tr];
        }
        tr = sig[tr][(int) S[pos]];

        int ba = INF;
        int bb = INF;
        
        if (term[tr] == 0) {
            ba = func(pos + 1, tr);
        }
        
        bb = 1 + func(pos + 1, 0);

        if (ba <= bb) {
            cout << S[pos];
            rec(pos + 1, tr);
        } else {
            cout << " " << S[pos];
            rec(pos + 1, 0);
        }
    }
}


int main(void) {
    while (cin >> N >> M && !(N == 0 && M == 0)) {
        cnt = 1;
        
        memset(sig, 0, sizeof(sig));
        
        for (int i = 0; i < N; i++) {
            cin >> EM[i];
            reverse(EM[i].begin(), EM[i].end());
            add(EM[i]);
        }

        aho();

        getline(cin, S);

        int ans = 0;
        
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
