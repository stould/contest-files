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

const int MAXN = 10005;

int N, M, K;
int T[MAXN];
int P[MAXN][15];
int F[MAXN];
vector<pair<int, int> > G[MAXN];
int dist[MAXN][1 << 11];

int main(void) {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        cin >> T[i];

        for (int j = 0; j < T[i]; j++) {
            cin >> P[i][j];

            P[i][j] -= 1;

            F[i] |= (1 << P[i][j]);
        }
    }

    for (int i = 0; i < M; i++) {
        int X, Y, Z;
        
        cin >> X >> Y >> Z;

        X -= 1;
        Y -= 1;

        G[X].push_back(make_pair(Y, Z));
        G[Y].push_back(make_pair(X, Z));
    }

    memset(dist, 63, sizeof(dist));
    priority_queue<pair<int, pair<int, int> > > q;

    vector<int> build;
    
    for (int j = 0; j < 10; j++) {
        if (F[0] & (1 << j)) {
            build.push_back(j);
        }
    }

    int len = (int) build.size();
    
    for (int j = 0; j < (1 << len); j++) {
        int next_mask = 0;
        
        for (int k = 0; k < len; k++) {
            if (j & (1 << k)) {
                next_mask |= (1 << build[k]);
            }
        }
        dist[0][next_mask] = 0;
        q.push(make_pair(0, make_pair(0, next_mask)));
    }

    q.push(make_pair(0, make_pair(0, F[0])));

    while (!q.empty()) {
        int ds   = -q.top().first;
        int now  = q.top().second.first;
        int mask = q.top().second.second;
        q.pop();

        if (dist[now][mask] < ds) continue;

        for (int i = 0; i < (int) G[now].size(); i++) {
            int next = G[now][i].first;
            int next_dist = dist[now][mask] + G[now][i].second;

            int next_mask = mask | F[next];

            if (dist[next][next_mask] > next_dist) {
                dist[next][next_mask] = next_dist;
                q.push(make_pair(-next_dist, make_pair(next, next_mask)));
            }
        }    
    }

    int ans = INT_MAX;
    
    for (int i = 0; i < (1 << K); i++) {
        for (int j = i; j < (1 << K); j++) {
            int ms = i | j;

            if (ms == (1 << K) - 1) {
                int a = INT_MAX;
                int b = INT_MAX;

                if (dist[N - 1][i] != 1061109567) {
                    a = dist[N - 1][i];
                }
                if (dist[N - 1][j] != 1061109567) {
                    b = dist[N - 1][j];
                }
                chmin(ans, max(a, b));
            }
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
