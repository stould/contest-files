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

const int MAXN = 2550;
const int INF = 101010;

int T, E;
int N;

int vis[MAXN];
int memo[MAXN];

vector<int> graph[MAXN];

pair<int, int> bfs(int x) {
    queue<int> q;

    q.push(x);

    int i;
    int best = 0, cnt = 0;

    for (i = 0; i < MAXN; i++) {
        memo[i] = 0;
        vis[i] = -INF;
    }

    vis[x] = 0;

    for ( ; !q.empty(); ) {
        int curr = q.front(); q.pop();

        for (i = 0; i < graph[curr].size(); i++) {
            int u = graph[curr][i];

            if (vis[u] == -INF) {
                vis[u] = vis[curr] + 1;
                q.push(u);
            }
        }
    }

    for (i = 0; i < 2500; i++) {
        if (vis[i] != -INF) {
            memo[vis[i]] += 1;
        }
    }
    for (i = 1; i < 2500; i++) {
        if (vis[i] != -INF && memo[vis[i]] > best) {
            best = memo[vis[i]];
            cnt = i;
        }
    }

    return make_pair(best, cnt);
}

int main(void) {
    freopen("i.in", "r", stdin);
    E = in();

    int i, j;

    for (i = 0; i < E; i++) {
        N = in();

        for (j = 0; j < N; j++) {
            int x = in();

            graph[i].push_back(x);
        }
    }

    T = in();

    for ( ; T--; ) {
        int x = in();

        pair<int, int> pr = bfs(x);

        if (pr.first == 0) {
            printf("0\n");
        } else {
            printf("%d %d\n", pr.first, pr.second);
        }
    }

    return 0;
}
