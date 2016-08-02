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

const int INF = INT_MAX / 5;
const int MAXN = 30010;
const int MAX_LOG = 18;

int N, Q, T;
vector<pair<int, Int> > tree[MAXN];
Int dist[MAXN];
int lca[MAXN][MAX_LOG];
int height[MAXN];
string S;

void dfs(int node, Int curr_cost, int p) {
    dist[node] = curr_cost;    
    lca[node][0] = p;
    
    for (int i = 1; i < MAX_LOG; i++) {
        lca[node][i] = lca[lca[node][i - 1]][i - 1];
    }
       
    for (auto& next : tree[node]) {
        if (next.first == p) continue;
        height[next.first] = height[node] + 1;
        
        dfs(next.first, curr_cost + next.second, node);
    }
}


int getLca(int p, int q) {
    if (height[q] > height[p]) {
        swap(p, q);
    }

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (height[p] - (1 << i) >= height[q]) {
            p = lca[p][i];
        }
    }
    
    if (p == q) return p;

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (lca[p][i] != -1 && lca[p][i] != lca[q][i]) {
            p = lca[p][i];
            q = lca[q][i];
        }
    }
    
    return lca[p][0];
}

Int getDist(int p, int q) {    
    return dist[p] + dist[q] - 2 * dist[getLca(p, q)];
}


int getKth(int node, int h) {
    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (h - (1 << i) >= 0) {
            h -= (1 << i);
            node = lca[node][i];
        }
    }
    return node;
}

int query(int a, int b, int k) {
    int lc = getLca(a, b);

    int ha = height[a] - height[lc];

    if (ha >= k) {
        return getKth(a, k);
    } else {
        return getKth(b, height[b] - height[lc] - (k - ha));
    }
}

int main(void) {
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        scanf("%d", &N);

        for (int i = 0; i <= N; i++) {
            tree[i].clear();
        }
        
        for (int i = 1; i < N; i++) {
            int a, b;
            Int c;
            scanf("%d%d%lld", &a, &b, &c);

            tree[a].push_back(make_pair(b, c));
            tree[b].push_back(make_pair(a, c));
        }

        dfs(1, 0, 1);
    
        while (1) {
            int a, b;
            cin >> S;
            
            if (S == "DONE") break;

            cin >> a >> b;
            
            if (S == "DIST") {
                //printf("%d %d\n", a, b);
                printf("%lld\n", getDist(a, b));
            } else {
                int k;
                scanf("%d", &k);
                if (a == b || k == 1) {
                    printf("%d\n", a);
                } else {
                    printf("%d\n", query(a, b, k - 1));
                }
            }
        }
    }
    
    return 0;
}
