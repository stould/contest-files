#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) {
    a = (a > b) ? b : a;
}
template<typename T> void chmax(T& a, T b) {
    a = (a < b) ? b : a;
}
int in() {
    int x;
    scanf("%d", &x);
    return x;
}

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 1010;
int N, M;

vector<int> graph[MAXN];

bool dp[MAXN][MAXN];
bool dp_mark[MAXN][MAXN];

bool func(int x, int y) {
    if (x == y) {
        if (x == 1) {
            return true; 
        } else {
            return false;
        }
    }

    bool& ans = dp[x][y];

    if (!dp_mark[x][y]) {
        int i;
        int j;

        ans = false;

        for (i = 0; i < (int) graph[x].size(); i++) {
            for (j = 0; j < (int) graph[y].size(); j++) {
                int u = graph[x][i];
                int v = graph[y][j];

                ans &= func(u, v);                                                
            }
        }
        dp_mark[x][y] = true;
    }

    return ans;
}


int main(void) {
    freopen("i.in", "r", stdin);
    int i;
    int j;
    
    for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
        for (i = 0; i <= N; i++) {
            graph[i].clear();       
        }

        for (i = 0; i < M; i++) {
            int x = in();
            int y = in();
            graph[y].push_back(x);    
        }

        int ans = 0;

        memset(dp_mark, false, sizeof(dp_mark));

        for (i = 2; i <= N; i++) {
            for (j = 2; j <= N; j++) if (i != j) {
                bool s = func(i, j);

                if (s) {
                    ans += 1;
                    printf("%d %d\n", i, j);
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
