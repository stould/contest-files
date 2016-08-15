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

const int MAXN = 1010;
const int INF = 1001010;

int T;
int N, M;
char S[200][200];

int dist[MAXN][MAXN];
int buffDist[MAXN][MAXN];

int dx[2] = {1, 0};
int dy[2] = {0, 1};

int cv(int i, int j) {
    return i * (M + 1) + j;
}

void bfs(int si, int sj) {
    queue<pair<int, int> > q;
    q.push(make_pair(si, sj));

    memset(buffDist, 63, sizeof(buffDist));

    for ( ; !q.empty(); ) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        int now = cv(xx, yy);
        
        for (int i = 0; i < 2; i++) {
            int ii = xx + dx[i];
            int jj = yy + dy[i];
            
            if (ii >= 0 && ii < N && jj >= 0 && jj < M && S[ii][jj] != '#') {
                int pos = cv(ii, jj);
                
                if (buffDist[pos] > buffDist[now] + 1) {
                    buffDist[pos] = buffDist[now] + 1;
                    q.push(make_pair(ii, jj));
                }
            }
        }
    }
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> M >> N;

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                dist[i][j] = INF;
            }
        }

        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> S[i][j];
            }
        }


        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if ((i == 0 && j == 0) || (i == N - 1 && j == M - 1) || (S[i][j] == '*')) {
                    bfs(i, j);
                }
            }
        }

        pair<Flow, Cost> ans = flow(G, cv(1, 1), cv(N, M), 2);

        int as = -ans.second;

        if (S[1][1] == '#') {
            as += 1;
        }
        
        cout << ans.first << " " << as << endl;
    }
    return 0;
}
