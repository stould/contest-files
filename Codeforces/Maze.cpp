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

const int MAXN = 550;
int N, M, K;
int vis[MAXN][MAXN];

string maze[MAXN];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main(void) {
    N = in();
    M = in();
    K = in();

    int i, j, k;

    for (i = 0; i < N; i++) {
        cin >> maze[i];
    }

    memset(vis, 0, sizeof(vis));

    pair<int, int> bg = make_pair(-1, -1);

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) if (maze[i][j] == '.') {
            bg = make_pair(i, j);
        }
    }

    memset(vis, 0, sizeof(vis));

    queue<pair<int, int> > q; q.push(bg);
    vector<pair<int, int> > poss;

    for ( ; !q.empty(); ) {
        pair<int, int> curr = q.front(); q.pop();

        if (vis[curr.first][curr.second]) continue;
        vis[curr.first][curr.second] = 1;
        poss.push_back(curr);

        for (int k = 0; k < 4; k++) {
            int ni = curr.first + dx[k];
            int nj = curr.second + dy[k];


            if (ni >= 0 && nj >= 0 && ni < N && nj < M && maze[ni][nj] == '.') {
                q.push(make_pair(ni, nj));
            }
        }
    }

    for (int i = poss.size() - 1; i >= 0 && K > 0; i--, K--) {
        maze[poss[i].first][poss[i].second] = 'X';
    }

    for (i = 0; i < N; i++) {
        cout << maze[i] << "\n";
    }

    return 0;
}
