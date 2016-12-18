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

const int MAXN = 1010;

int N;
int X[MAXN], Y[MAXN];
bool vis[MAXN];

int dfs(int x, const vector<vector<int> >& G) {
    vis[x] = true;

    int ans = 1;

    for (int i = 0; i < (int) G[x].size(); i++) {
        int u = G[x][i];

        if (!vis[u]) {
            ans += dfs(u, G);
        }
    }
    
    return ans;
}

int main(void) {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    Int l = 0, h = 100000000000;
    int ans = 0;

    while (l <= h) {
        Int m = (l + h) / 2;

        vector<vector<int> > G(N);
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;

                long long dst = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
                
                if (dst <= m) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }

        memset(vis, false, sizeof(vis));

        int cnt = 0;
        
        cnt += dfs(0, G);
        
        if (cnt == N) {
            h = m - 1;
            ans = m;
        } else {
            l = m + 1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
