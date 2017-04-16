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

const int MAXN = 1010;
const double INF = 100010100100100100.0;

int N, M;
double dist[MAXN];
vector<pair<int, pair<int, int> > > G[MAXN];

double getDist(double tempo) {
    priority_queue<pair<double, int> > q;
    q.push(make_pair(0, 1));
    
    for (int i = 0; i < MAXN; i++) {
        dist[i] = INF;
    }

    dist[1] = 0;

    while (!q.empty()) {
        double curr_dist = -q.top().first;
        int now = q.top().second;
        q.pop();

        if (curr_dist > dist[now]) continue;

        if (now == N) {
            break;
        }

        for (int i = 0; i < (int) G[now].size(); i++) {
            int next = G[now][i].first;
            double next_dist = dist[now] + G[now][i].second.first * tempo + G[now][i].second.second;

            if (dist[next] > next_dist) {
                dist[next] = next_dist;
                q.push(make_pair(-next_dist, next));
            }
        }
    }
    
    return dist[N];
}

int main(void) {
    while (cin >> N >> M) {
        for (int i = 0; i < MAXN; i++) {
            G[i].clear();
        }
        for (int i = 0; i < M; i++) {
            int A, B, P, Q;
            cin >> A >> B >> P >> Q;

            G[A].push_back(make_pair(B, make_pair(P, Q)));
            G[B].push_back(make_pair(A, make_pair(P, Q)));
        }

        double l = 0, h = 24 * 60;
        double best = max(getDist(0), getDist(24 * 60));

        for (int x = 0; x < 100; x++) {
            double ll = l + (h - l) / 3.0;
            double hh = h - (h - l) / 3.0;
            
            double dl = getDist(ll);
            double dh = getDist(hh);
            
            //cout << fixed << setprecision(5) << ll << " " << hh << " " << dl << " " << dh << endl;
            
            best = max(best, max(dl, dh));

            double sl = INF;
            double sh = INF;

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < (int) G[i].size(); j++) {
                    sl = min(sl, G[i][j].second.first * ll + G[i][i].second.second);
                    sh = min(sh, G[i][j].second.first * hh + G[i][i].second.second);
                }
            }

            if (dl < dh) {
                l = ll;
            } else {
                h = hh;
            }  
        }

        cout << fixed << setprecision(5) << best << "\n";
    }    
    return 0;
}
