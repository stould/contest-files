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
bool ok[MAXN][MAXN];

bool func(int x, int y) {
    if (x == y) {
        if (x == 1) {
            return true;
        } else {
            return false;
        }
    }

    bool& ans = dp[x][y];

    if (!ok[x][y]) {
        int i;
        int j;

        ans = true;

        for (i = 0; i < (int) graph[x].size(); i++) {
            for (j = 0; j < (int) graph[y].size(); j++) {
                int u = graph[x][i];
                int v = graph[y][j];

                if (!func(x, v)) ans = false;
                if (!func(u, y)) ans = false;
                if (!func(u, v)) ans = false;
            }
        }

        ok[x][y] = true;
    }

    return ans;
}

int main(void) {
    int i;
    int j;
    int A, B;

    for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
        for (i = 0; i < M; i++) {
            A = in();
            B = in();

            graph[B].push_back(A);
        }

        memset(ok, false, sizeof(false));

        int ans = 0;

        for (i = 2; i <= N; i++) {
            for (j = 2; j <= N; j++) if (i != j) {
                bool now = func(i, j);

                if (now) {
                    ans += 1;
                    printf("%d %d\n", i, j);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
