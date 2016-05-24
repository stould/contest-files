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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 110;

int N, M, L;
char S[MAXN][MAXN][MAXN];
int dist[MAXN][MAXN][MAXN];

int dx[4] {-1, 1, 0, 0};
int dy[4] {0, 0, -1, 1};

int main(void) {
    while (cin >> N >> M >> L) {
        if (N == 0 && M == 0 && L == 0) break;
        pair<int, pair<int, int> > ps, pe;
        
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < M; k++) {
                    cin >> S[i][j][k];
                    if (S[i][j][k] == 'S') {
                        ps = make_pair(i, make_pair(j, k));
                    }
                    if (S[i][j][k] == 'E') {
                        pe = make_pair(i, make_pair(j, k));
                    }
                }
            }
        }
        memset(dist, 63, sizeof(dist));

        queue<pair<int, pair<int, int> > > q;
        q.push(ps);

        dist[ps.first][ps.second.first][ps.second.second] = 0;
        
        while (!q.empty()) {
            pair<int, pair<int, int> > now = q.front();
            q.pop();
            //cout << now.first << " " << now.second.first << " " << now.second.second << " " << dist[now.first][now.second.first][now.second.second] << "\n";
            //if (now == pe) break;

            if (S[now.first][now.second.first][now.second.second] == '-') {
                if (now.first + 1 < L && S[now.first + 1][now.second.first][now.second.second] == '-') {
                    if (dist[now.first][now.second.first][now.second.second] + 1 < dist[now.first + 1][now.second.first][now.second.second]) {
                        dist[now.first + 1][now.second.first][now.second.second] = 1 + dist[now.first][now.second.first][now.second.second];
                        q.push(make_pair(now.first + 1, make_pair(now.second.first, now.second.second)));
                    }
                }
                if (now.first - 1 >= 0 && S[now.first - 1][now.second.first][now.second.second] == '-') {
                    if (dist[now.first][now.second.first][now.second.second] + 1 < dist[now.first - 1][now.second.first][now.second.second]) {
                        dist[now.first - 1][now.second.first][now.second.second] = 1 + dist[now.first][now.second.first][now.second.second];
                        q.push(make_pair(now.first - 1, make_pair(now.second.first, now.second.second)));
                    }
                }
            }

            for (int i = 0; i < 4; i++) {
                int di = now.second.first  + dx[i];
                int dj = now.second.second + dy[i];

                if (di >= 0 && dj >= 0 && di < N && dj < M && S[now.first][di][dj] != '#') {
                    if (dist[now.first][di][dj] > dist[now.first][now.second.first][now.second.second] + 1) {
                        dist[now.first][di][dj] = dist[now.first][now.second.first][now.second.second] + 1;
                        q.push(make_pair(now.first, make_pair(di, dj)));
                    }
                }
            }
        }
        //cout << pe.first << " " << pe.second.first << " " << pe.second.second <<" \n";
        int ans = dist[pe.first][pe.second.first][pe.second.second];

        if (ans >= 1000000) {
            ans = -1;
        }
        cout << ans << "\n";
    }
    return 0;
}
