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

const int MAXN = 110;
const int INF = 100001010;

int N, K;
vector<pair<int, int> > tree[MAXN];
int apple[MAXN], subTree[MAXN], subSize[MAXN];
int dp[MAXN][MAXN];
int memo[MAXN][MAXN];
vector<int> line;

int func(int pos, int used) {
    if (pos >= (int) line.size()) {        
        if (used == 0) {
            return 0;
        } else {
            return -INF;
        }
    } else {
        int& ans = memo[pos][used];
        
        if (ans == -1) {
            ans = -INF;

            for (int i = 0; i <= subSize[line[pos]]; i++) {
                int next = dp[line[pos]][i] + func(pos + 1, used - i);
                chmax(ans, next);
            }
        }
        
        return ans;
    }
}

void dfs(int node, int parent) {
    subTree[node] = apple[node];
    subSize[node] = 1;

    for (auto& it: tree[node]) {
        if (it.first != parent) {
            apple[it.first] += it.second;
            
            dfs(it.first, node);

            subSize[node] += subSize[it.first];
            subTree[node] += subTree[it.first];
        }
    }

    dp[node][0] = subTree[node];
    
    if (subSize[node] == 1) {
        dp[node][subSize[node]] = 0;
    } else {
        dp[node][subSize[node] - 1] = apple[node];
    }

    line.clear();

    for (int i = 0; i < (int) tree[node].size(); i++) {
        int next = tree[node][i].first;
        
        if (next != parent) {
            line.push_back(next);
        }
    }

    for (int i = 1; i < subSize[node]; i++) {
        memset(memo, -1, sizeof(memo));
        dp[node][i] = apple[node] + func(0, i);
    }
}

int main(void) {
    cin >> N >> K;

    for (int i = 0; i < N - 1; i++) {
        int a, b, c;

        cin >> a >> b >> c;

        tree[a].push_back(make_pair(b, c));
        tree[b].push_back(make_pair(a, c));
    }

    dfs(1, -1);

    cout << dp[1][subSize[1] - 1 - K] << "\n";
    
    return 0;
}
