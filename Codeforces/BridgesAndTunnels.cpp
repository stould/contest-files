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

const int MAXN = 4040;
const Int INF = 10000100100100LL;
    
int N, M, P;
pair<Int, Int> dist[MAXN];
vector<pair<int, pair<Int, char> > > G[MAXN];

pair<Int, Int> func(int st, int ed) {
    priority_queue<pair<Int, pair<Int, int> > > q;
    q.push(make_pair(0, make_pair(0, st)));

    for (int i = 0; i < N; i++) {
        dist[i] = make_pair(INF, INF);
    }

    dist[st] = make_pair(0, 0);

    while (!q.empty()) {
        int now = q.top().second.second;
        q.pop();

        for (int i = 0; i < (int) G[now].size(); i++) {
            int next = G[now][i].first;
            Int ct   = G[now][i].second.first;
            char kind = G[now][i].second.second;

            pair<Int, Int> next_dist = dist[now];

            if (kind == 'O') {
                next_dist.first += ct;
            } else {
                next_dist.second += ct;
            }

            if (dist[next] > next_dist) {
                dist[next] = next_dist;
                q.push(make_pair(-next_dist.first, make_pair(-next_dist.second, next)));
            }
        }
    }

    return dist[ed];
}

int main(void) {
    cin >> N >> M >> P;

    for (int i = 0; i < M; i++) {
        int A, B, C;
        char D;
        
        cin >> A >> B >> C >> D;

        G[A].push_back(make_pair(B, make_pair(C, D)));
        G[B].push_back(make_pair(A, make_pair(C, D)));
    }

    for (int i = 0; i < P; i++) {
        int A, B;

        cin >> A >> B;

        pair<Int, Int> ans = func(A, B);

        if (ans.first + ans.second >= INF) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << ans.first << " " << ans.first + ans.second << endl;
        }
    }
    return 0;
}
