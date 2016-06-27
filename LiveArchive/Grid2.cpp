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

const int MAXN = 55;

int T, N, M;
int P[MAXN][MAXN];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void) {
    cin >> T;

    while (T--) {
        cin >> N >> M;

        set<pair<int, pair<pair<int, int>, pair<int, int>  > > > q;

        int sum = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> P[i][j];

                sum += P[i][j];
                
                for (int k = 0; k < 4; k++) {
                    int di = i + dx[k];
                    int dj = j + dy[k];

                    if (di >= 0 && dj >= 0 && di < N && dj < M) {
                        q.insert(make_pair(-(P[i][j] + P[di][dj]), make_pair(make_pair(i, j), make_pair(di, dj))));
                    }
                }
            }
        }

        int ans = 0;
        
        while (!q.empty() && sum > 0) {
            int curr = -(*q.begin()).first;
            int pi = (*q.begin()).second.first.first;
            int pj = (*q.begin()).second.first.second;
            int qi = (*q.begin()).second.second.first;
            int qj = (*q.begin()).second.second.second;
            q.erase(q.begin());

            if (curr == 0) continue;

            if (P[pi][pj] + P[qi][qj] != curr) {
                q.insert(make_pair(-(P[pi][pj] + P[qi][qj]), make_pair(make_pair(pi, pj), make_pair(qi, qj))));
                continue;
            }
            int val = max(1, min(P[pi][pj], P[qi][qj]));
            ans += val;

            if (P[pi][pj] >= val) {
                P[pi][pj] -= val;
            }
            if (P[qi][qj] >= val) {
                P[qi][qj] -= val;
            }
            if (P[pi][pj] + P[qi][qj] > 0) {
                q.insert(make_pair(-(P[pi][pj] + P[qi][qj]), make_pair(make_pair(pi, pj), make_pair(qi, qj))));
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}
