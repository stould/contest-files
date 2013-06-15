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

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 55;
const int INF = 1061109567;
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

int N, M, v[MAXN][MAXN], dist[MAXN][MAXN][1<<7] = {0};

int main(void) {
    scanf("%d%d", &N, &M);
    REP(i, N) REP(j, M) scanf("%d", &v[i][j]);

    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(0, 0)));

    memset(dist, 63, sizeof(dist));
    dist[0][0][0] = 0;

    while(!q.empty()) {
        pair<int, pair<int, int> > p = q.front();
        q.pop();
        int curr = p.first, now_i = p.second.first, now_j = p.second.second;

        int now = (curr + 1) % 10;
        REP(i, 5) {
            int ni = now_i + dx[i], nj = now_j + dy[i];
            if(ni >= 0 && nj >= 0 && ni < N && nj < M) {
                if((((v[ni][nj] + curr) % 10) - ((v[now_i][now_j] + curr)) % 10) < 2 && dist[ni][nj][now] >= INF) {
                    q.push(make_pair(now, make_pair(ni, nj)));
                    dist[ni][nj][now] = dist[now_i][now_j][curr] + 1;
                }
            }
        }
    }
    int ans = INF;
    REP(i, 10) ans = min(ans, dist[N-1][M-1][i]);
    printf("%d\n", ans);
    return 0;
}
