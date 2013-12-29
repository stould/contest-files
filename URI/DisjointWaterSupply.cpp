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
<<<<<<< HEAD

bool dp[MAXN][MAXN];
bool ok[MAXN][MAXN];

bool func(int x, int y) {
    if (x == y) {
        if (x == 1) {
            return true;
        } else {
            return false;
=======

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
>>>>>>> f4bc27e725b335fa3490fc7ba90eca3af667e707
        }
        dp_mark[x][y] = true;
    }

<<<<<<< HEAD
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
=======
    return ans;
}

>>>>>>> f4bc27e725b335fa3490fc7ba90eca3af667e707

int main(void) {
    int i;
    int j;
<<<<<<< HEAD
    int A, B;
=======
    
    for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
        for (i = 0; i <= N; i++) {
            graph[i].clear();       
        }
>>>>>>> f4bc27e725b335fa3490fc7ba90eca3af667e707

    for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
        for (i = 0; i < M; i++) {
<<<<<<< HEAD
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
=======
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
>>>>>>> f4bc27e725b335fa3490fc7ba90eca3af667e707
                    ans += 1;
                    printf("%d %d\n", i, j);
                }
            }
        }
<<<<<<< HEAD
=======

>>>>>>> f4bc27e725b335fa3490fc7ba90eca3af667e707
        printf("%d\n", ans);
    }
    return 0;
}
