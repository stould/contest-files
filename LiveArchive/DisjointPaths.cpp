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

const int MAXN = 100;
const int INF = 1000000;

int T, N, K;
vector<pair<int, int> > tree[MAXN];
int dp[MAXN][MAXN][2];
int val[MAXN];
int memo[MAXN][MAXN];
vector<int> line;

void dfs(int node, int parent) {
    for (auto& it: tree[node]) {
        if (it.first != parent) {
            val[node] = it.second;
            dfs(it.first, node);
        }
    }
    
    for (auto& it: tree[node]) {
        if (it.first != parent) {

        }
    }

    line.clear();

    for (int i = 0; i < (int) tree[node].size(); i++) {
        int next = tree[node][i].first;
        
        if (next != parent) {
            line.push_back(next);
        }
    }
    for (auto& it: tree[node]) {
        if (it.first != parent) {
            for (int i = 0; i <= K; i++) {
                memset(memo, -1, sizeof(memo));
                dp[node][i] = func(0, i);
            }
        }
    }
}

int main(void) {
    cin >> T;
    while (T--) {
        cin >> N >> K;

        for (int i = 0; i < N - 1; i++) {
            int a, b, c;
            cin >> a >> b >> c;

            tree[a].push_back(make_pair(b, c));
            tree[b].push_back(make_pair(a, c));            
        }
    }
    return 0;
}
