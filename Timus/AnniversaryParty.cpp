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

const int MAXN = 6060;

int N;
int P[MAXN];
vector<int> tree[MAXN];
int dp[MAXN][2];

void dfs(int node, int parent) {
    int use = 0;
    int not_use = 0;

    dp[node][1] = P[node];
    
    for (auto& it : tree[node]) {
        if (it != parent) {
            dfs(it, node);
            
            use += dp[it][0];
            not_use += max(dp[it][0], dp[it][1]);
        }
    }

    dp[node][1] = P[node] + use;
    dp[node][0] = not_use;
}
int main(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }
    
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 1);

    cout << max(dp[1][0], dp[1][1]) << "\n";
    
    return 0;
}
