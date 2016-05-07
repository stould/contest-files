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

int T;
int N, M;
string S[MAXN];
int dist[MAXN][MAXN][11];

int dx[4] = { 0, 0, -1, 1};
int dy[4] = {-1, 1,  0, 0};

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M;

        int si = 0, sj = 0;
        int ei = 0, ej = 0;
        
        for (int i = 0; i < N; i++) {
            cin >> S[i];

            for (int j = 0; j < M; j++) {
                if (S[i][j] == 'A') {
                    si = i;
                    sj = j;
                } else if (S[i][j] == 'B') {
                    ei = i;
                    ej = j;
                }
            }
        }

        int best = 0;
        
        priority_queue<pair<int, pair<int, pair<int, int> > > > q;
        q.push(make_pair(0, make_pair(0, make_pair(si, sj))));

        memset(dist, 63, sizeof(dist));
        
        dist[si][sj][0] = 0;

        while (!q.empty()) {
            int dst = q.top().first;
            int smallest = q.top().second.first;
            int pi = q.top().second.second.first;
            int pj = q.top().second.second.second;
            q.pop();
            
            if (dist[pi][pj][smallest] < dst) continue;

            if (pi == ei && ej == ej) {
                best = smallest;
            }

            for (int i = 0; i < 4; i++) {
                int qi = pi + dx[i];
                int qj = pj + dy[i];
                
                if (qi >= 0 && qj >= 0 && qi < N && qj < M) {
                    if (S[qi][qj] != '0' && dist[pi][pj] + 1 < dist[qi][qj]) {
                        int next_best = max(smallest, S[qi][qj] == 'B' ? 0 : S[qi][qj] - '0');
                        
                        dist[qi][qj][next_best] = 1 + dist[pi][pj][smallest];
                        q.push(make_pair(dist[qi][qj][next_best], make_pair(next_best, make_pair(qi, qj))));                        
                    }
                }
            }         
        }

        int ans = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (S[i][j] >= '0' && S[i][j] <= '9') {
                    ans += S[i][j] - '0';
                }
            }
        }
        if (dist[ei][ej][best] >= 100000) {
            ans = 0;
        } else {
            cout << ans << " " << dist[ei][ej][best] << " " << best << "\n";
            ans -= dist[ei][ej][best];
            ans += best;
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}
