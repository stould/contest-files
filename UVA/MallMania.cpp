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

const int MAXN = 2002;
const int INF = 1001010;

int N, M;

int graph[MAXN][MAXN];
int dist[MAXN][MAXN];

pair<int, int> q[MAXN*MAXN];

int head, tail;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool ok(int x, int y) {
    return (x >= 0 && y >= 0 && x <= 2000 && y <= 2000);
}

int func(void) {
    for ( ; head < tail; ) {
        int x = q[head].first;
        int y = q[head].second;

        head++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (ok(nx, ny) && dist[nx][ny] > dist[x][y] + 1 && graph[nx][ny] != 1) {
                dist[nx][ny] = dist[x][y] + 1;

                if (graph[nx][ny] == 2) {
                    return dist[nx][ny];
                }

                q[tail++] = make_pair(nx, ny);
            }
        }
    }

    return -1;
}

int main(void) {
    for ( ; scanf("%d", &N) == 1 && N != 0; ) {
        for (int i = 0; i < MAXN; i++) {
            for (int j = 0; j < MAXN; j++) {
                dist[i][j] = INF;
                graph[i][j] = 0;
            }
        }

        head = tail = 0;

        for (int i = 0; i < N; i++) {
            int x = in();
            int y = in();

            graph[x][y] = 1;
            dist[x][y] = 0;

            q[tail++] = make_pair(x, y);
        }

        M = in();

        for (int i = 0; i < M; i++) {
            int x = in();
            int y = in();

            graph[x][y] = 2;
        }

        printf("%d\n", func());
    }

    return 0;
}
