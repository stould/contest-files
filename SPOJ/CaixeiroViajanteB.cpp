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
typedef unsigned uint;

const int MAXN = 310;

int N, F;
int G[MAXN];
int par[MAXN], cst[MAXN], par_cst[MAXN];
bool vis[MAXN];
vector<pair<int, int> > tree[MAXN];

void dfs(int now, int p, int cost) {
    vis[now] = true;
    par[now] = p;
    cst[now] = cost;
	
    for (int i = 0; i < (int) tree[now].size(); i++) {
        int next = tree[now][i].first;
        int curr_cost = tree[now][i].second;
		
        if (!vis[next] && next != p) {
            par_cst[next] = curr_cost;
            dfs(next, now, cost + curr_cost);
        }
    }
}

int upTree(int now) {
    if (vis[now] or now == 1) {
        return 0;
    } else {
        vis[now] = true;
        return par_cst[now] + upTree(par[now]);		
    }
}

int main(void) {
    while (cin >> N >> F) {
        if (N == 0 && F == 0) break;
        for (int i = 0; i <= N; i++) {
            tree[i].clear();
            par[i] = -1;
            G[i] = 0;
            cst[i] = 0;
            par_cst[i] = 0;
            vis[i] = false;
        }
		
        for (int i = 0; i < N - 1; i++) {
            int A, B;
            cin >> A >> B;

            tree[A].push_back(make_pair(B, 1));
            tree[B].push_back(make_pair(A, 1));
        }

        dfs(1, -1, 0);

        for (int i = 0; i < F; i++) {
            int A;
            cin >> A;

            G[A] = 1;
        }

        memset(vis, false, sizeof(vis));
		
        int ans = 0;

        for (int i = 1; i <= N; i++) {
            if (G[i] == 1) {
                ans += upTree(i);
            }
        }
        
        cout << ans << endl;
    }
    return 0;
}
