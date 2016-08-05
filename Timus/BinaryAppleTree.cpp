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
const int INF = 1001010;

int N, K;
vector<pair<int, int> > tree[MAXN];
int apple[MAXN], subTree[MAXN], subSize[MAXN];
int dp[MAXN][MAXN];
int dp2[MAXN][MAXN];
vector<int> line;

int func(int pos, int used, int sum) {
    if (pos == (int) line.size()) {
        return used == 0 ? 0 : -INF;
    } else {
        int& ans = dp2[pos][used];
        
        if (ans == -1) {
            ans = 0;
            
            for (int i = 0; i <= used; i++) {
                if (i >= subSize[line[pos]]) break;
                cout << "Going " << line[pos] << " " << i << " " << dp[line[pos]][i] << "\n";
                chmax(ans, dp[line[pos]][i] + func(pos + 1, used - i, sum + dp[line[pos]][i]));
            }
        }

        //cout << "ans " << pos << " " << used << " " << ans << endl;
        
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
    dp[node][subSize[node]] = 0;

    line.clear();

    for (int i = 0; i < (int) tree[node].size(); i++) {
        int next = tree[node][i].first;
        
        if (next != parent) {
            line.push_back(next);
        }
    }

    for (int i = 1; i <= subSize[node]; i++) {
        memset(dp2, -1, sizeof(dp2));
        cout << node << " " << i << " " << max(0, func(0, i, 0)) << "\n";
        dp[node][i] = max(0, func(0, i, 0));
    }
    /*
      for (int i = 0; i < (int) tree[node].size(); i++) {
        int next = tree[node][i].first;
        
        if (next != parent) {
            for (int j = 0; j <= K; j++) {
                for (int k = 0; k <= K; k++) {
                    dp2[node][j] = max(dp2[node][j], dp2[next][j - k] + dp[next][j]);
                }
            }
        }
    } 
    */  
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

    cout << dp[1][K] << "\n";
    return 0;
}
