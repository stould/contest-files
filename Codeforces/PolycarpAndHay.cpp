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

int N, M;
Int K;
Int P[MAXN][MAXN], ans[MAXN][MAXN];
bool seen[MAXN][MAXN];
bool vis[MAXN][MAXN];

int dx[4] = {-1, 1,  0, 0};
int dy[4] = { 0, 0, -1, 1};

bool build_answer(int si, int sj, Int base) {
    queue<pair<int, int> > q;
    q.push(make_pair(si, sj));

    memset(vis, false, sizeof(vis));
    memset(ans, false, sizeof(ans));
    
    vis[si][sj] = true;
    
    Int whole = base;
    
    while (!q.empty()) {
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        ans[ci][cj] = base;

        for (int i = 0; i < 4; i++) {
            int ni = ci + dx[i];
            int nj = cj + dy[i];

            if (ni >= 0 && nj >= 0 && ni < N && nj < M) {
                if (P[ni][nj] >= base && !vis[ni][nj]) {
                    vis[ni][nj] = seen[ni][nj] = true;

                    if (whole < K) {
                        whole += base;
                        q.push(make_pair(ni, nj));
                    }
                }
            }
        }        
    }
    
    return whole == K;    
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M >> K;

    vector<pair<Int, pair<int, int> > > fl;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> P[i][j];
            fl.push_back(make_pair(P[i][j], make_pair(i, j)));
        }
    }
    
    sort(fl.begin(), fl.end());

    bool ok = false;
    Int sum = 0LL;
    
    for (int i = N * M - 1; i >= 0; i--) {
        int pi = fl[i].second.first;
        int pj = fl[i].second.second;

        sum += fl[i].first;
        
        if (K % fl[i].first == 0 && !seen[pi][pj]) {
            if (sum >= K) {
                bool can = build_answer(pi, pj, fl[i].first);
                
                if (can) {
                    ok = true;
                    break;
                }
            }
        }
    }

    if (!ok) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    
    return 0;
}
