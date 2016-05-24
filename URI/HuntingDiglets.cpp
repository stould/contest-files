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

const int MAXN = 350;

int N;
int P[MAXN];
vector<int> G[MAXN];
bool vis[MAXN][MAXN];
vector<int> cnt[MAXN][MAXN];

void dfs(int rt, int node, int t) {
    if (t > 0 && node == rt) {
        cnt[t][node].push_back(rt);
    }

    vis[node][t] = true;
    
    for (int i = 0; i < (int) G[node].size(); i++) {
        int next = G[node][i];

        if (t + 1 < MAXN && !vis[next][t + 1]) {
            dfs(rt, next, t + 1);
        }
    }
}

int main(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> P[i];

        G[i].push_back(P[i]);
    }

    for (int i = 1; i <= N; i++) {
        memset(vis, 0, sizeof(vis));
        dfs(i, i, 0);
    }

    for (int i = 1; i <= N; i++) {
        set<int> seen;
        
        for (int j = 1; j <= N; j++) {
            seen.insert(cnt[i][j].begin(), cnt[i][j].end());
        }

        if (seen.size() == N) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
