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

int N, C;
vector<int> tree[MAXN];
int color[MAXN];
vector<int> pr[MAXN];
int ans[MAXN];

void dfs(int node) {
    if (pr[color[node]].empty()) {
        ans[node] = -1;
    } else {
        ans[node] = pr[color[node]].back();
    }
    pr[color[node]].push_back(node);

    for (int i = 0; i < (int) tree[node].size(); i++) {
        dfs(tree[node][i]);
    }

    pr[color[node]].pop_back();
}

int main(void) {
    cin >> N >> C;

    for (int i = 2; i <= N; i++) {
        int p;
        cin >> p;

        tree[p].push_back(i);
    }
    for (int i = 1; i <= N; i++) {
        cin >> color[i];
    }

    dfs(1);

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
