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

const int MAXN = 1010;

int T, N;
int P[MAXN];
bool vis[MAXN];
vector<int> G[MAXN];

void dfs(int x) {
    vis[x] = true;
    
    for (int i = 0; i < (int) G[x].size(); i++) {
        int u = G[x][i];

        if (!vis[u]) {
            dfs(u);
        }
    }
}

int main(void) {
    cin >> T;

    while (T--) {
        cin >> N;

        for (int i = 0; i < MAXN; i++) {
            G[i].clear();
        }

        for (int i = 1; i <= N; i++) {
            cin >> P[i];
            vis[i] = false;
            G[i].push_back(P[i]);
        }

        int ans = 0;
        
        for (int i = 1; i <= N; i++) {
            if (!vis[i]) {
                ans += 1;
                dfs(i);
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
