#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

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

const int MAXN = 110;
const int INF = 1001000010;

int T, N, M, a, b, c;

int dist[MAXN][MAXN];
int path[MAXN][MAXN];

int main(void) {
    freopen("i.in", "r", stdin);
    //freopen("o.out", "w", stdout);

    int i, j, k;

    T = in();

    for ( ; T--; ) {
        N = in(), M = in();

        for (i = 1; i <= N; i++) {
            for (j = 1; j <= N; j++) {
                dist[i][j] = INF;
                path[i][j] = 0;
            }
        }

        for(i = 0; i < M; i++) {
            a = in(), b = in(), c = in();
            dist[a][b] = c;
            if (a == 1 || b == 1) {
                dist[b][a] = c;
            }
            path[a][b] = path[b][a] = 2;
        }

        for (k = 1; k <= N; k++) {
            for (i = 1; i <= N; i++) {
                for (j = 1; j <= N; j++) {
                    if (j != 1 || (j == 1 && (path[i][k] + path[k][j] - 1) % 2 == 1)) {
                        if (dist[i][k] + dist[k][j] < dist[i][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                            path[i][j] = path[i][k] + path[k][j] - 1;
                        }
                    }
                }
            }
        }

        for (i = 2; i <= N; i++) {
            printf("%d %d %d\n", i, dist[1][i], path[1][i]);
        }

        if (dist[1][1] == INF) {
            puts("impossivel");
        } else {
            printf("%d - %d\n", dist[1][1], path[1][1]);
        }
    }

    return 0;
}
