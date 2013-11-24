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
typedef unsigned uint;

int T;

char str[10][10];

bool vis[10][10][10][10];

int dx[4] = {2, 2, -2, -2};
int dy[4] = {2, -2, -2, 2};

bool ok;

void dfs(int a, int b, int c, int d) {
    vis[a][b][c][d] = 1;

    int i;
    int j;

    if (ok) return;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            int ni = a + dx[i];
            int nj = b + dy[i];
            int mi = c + dx[j];
            int mj = d + dy[j];

            if (!(ni >= 0 && nj >= 0 && ni < 8 && nj < 8)) {
                continue;
            }
            if (!(mi >= 0 && mj >= 0 && mi < 8 && mj < 8)) {
                continue;
            }

            if (ni == mi && nj == mj && str[ni][nj] != '#') {
                ok = true;
            }
            if (vis[ni][nj][mi][mj]) continue;
            dfs(ni, nj, mi, mj);
        }
    }
}

int main(void) {
    T = in();

    int i, j;

    for ( ; T--; ) {
        for (i = 0; i < 8; i++) {
            scanf("%s", str[i]);
        }

        memset(vis, false, sizeof(vis));

        int a, b, c, d, x = 0;

        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (str[i][j] == 'K') {
                    if (x) {
                        c = i;
                        d = j;
                    }  else {
                        a = i;
                        b = j;
                        x = 1;
                    }
                }
            }
        }

        ok = false;

        dfs(a, b, c, d);

        if (ok) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
