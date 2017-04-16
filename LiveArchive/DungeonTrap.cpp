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
const int INF = 1061109567;
int T;
int N, M;
string S[MAXN];
int dist[MAXN][MAXN][15];
int best[MAXN][MAXN];

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

        priority_queue<pair<int, pair<int, pair<int, int> > > > q;
        q.push(make_pair(0, make_pair(0, make_pair(si, sj))));

        memset(dist, 63, sizeof(dist));

        dist[si][sj][0] = 0;
        
        while (!q.empty()) {
            int dst = -q.top().first;
            int smallest = q.top().second.first;
            int pi = q.top().second.second.first;
            int pj = q.top().second.second.second;
            q.pop();

            if (dist[pi][pj][smallest] < dst) continue;
            if (S[pi][pj] == 'B') continue;
            //cout << pi << " " << pj << " " << dist[pi][pj] << endl;
            for (int i = 0; i < 4; i++) {
                int qi = pi + dx[i];
                int qj = pj + dy[i];
                
                if (qi >= 0 && qj >= 0 && qi < N && qj < M) {
                    if (S[qi][qj] != '0') {
                        int dst = S[qi][qj] == 'B' ? 0 : S[qi][qj] - '0';
                        int next_best = max(smallest, dst);
                        
                        if (dist[qi][qj][next_best] > dist[pi][pj][smallest] + dst) {                           
                            dist[qi][qj][next_best] = dist[pi][pj][smallest] + dst;
                            //best[qi][qj][next_best] = max(best[pi][pj][smallest], next_best);
                            q.push(make_pair(-dist[qi][qj][next_best], make_pair(next_best, make_pair(qi, qj))));
                        }
                    }
                }
            }         
        }
        
        int all = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (S[i][j] > '0' && S[i][j] <= '9') {
                    all += S[i][j] - '0';
                }
            }
        }
        int ans = 0;
        
        for (int i = 0; i <= 9; i++) {
            if (dist[ei][ej][i] < INF) {
                //cout << i << " " << dist[ei][ej][i] << " " << all << endl;
                ans = max(ans, all - dist[ei][ej][i] + i);
            }
        }
        
        //cout << ans << " " << dist[ei][ej] << " " << best[ei][ej] << "\n";
        if (ans >= INF) {
            ans = 0;
        }
        
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}
