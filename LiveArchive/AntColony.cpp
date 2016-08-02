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

const int MAXN = 100005;
const int MAX_LOG = 20;

int N, Q;
vector<pair<int, Int> > tree[MAXN];
int lca[MAXN][MAX_LOG];
Int dist[MAXN];
int height[MAXN];

void dfs(int node, Int curr_cost, int p) {
    dist[node] = curr_cost;
    lca[node][0] = p;
    
    for (int i = 1; i < MAX_LOG; i++) {
        lca[node][i] = lca[lca[node][i - 1]][i - 1];        
    }

       
    for (int i = 0; i < (int) tree[node].size(); i++) {
        int next = tree[node][i].first;
        Int cost = tree[node][i].second;

        if (next == p) continue;

        height[next] = height[node] + 1;

        dfs(next, curr_cost + cost, node);
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

Int getCost(int p, int q) {
    return dist[p] + dist[q] - 2 * dist[getLca(p, q)];
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    while (cin >> N && N != 0) {
        for (int i = 0; i <= N; i++) {
            tree[i].clear();
        }
        for (int i = 1; i < N; i++) {            
            int A;
            Int P;
            
            cin >> A >> P;

            tree[A].push_back(make_pair(i, P));
            tree[i].push_back(make_pair(A, P));
        }

        dfs(0, 0, 0);

        cin >> Q;

        for (int q = 0; q < Q; q++) {
            int A, B;
            cin >> A >> B;

            //cout << A << " " << B << " " << getLca(A, B) << endl;

            if (q) cout << " ";

            cout << getCost(A, B);
        }

        cout << endl;
    }
    return 0;
}
