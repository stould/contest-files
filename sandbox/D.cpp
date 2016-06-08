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

const int MAXN = 301;
const int INF = 100000110;

int N, M, P;
int V[MAXN][MAXN];
vector<pair<int, int> > buff[MAXN * MAXN];
int dp[MAXN * MAXN];

int dist(int a, int b, int p, int q) {
    return abs(a - p) + abs(b - q);
}

void gen() {
    cout << "300 300 11\n";
    srand(time(NULL));
    vector<int> vs(300 * 300);
    int pos = 0;
    int val = 1;
    for (int i = 0; i < 90000; i++) {
        vs[i] = val;

        if (i % 10000 == 0) {
            val += 1;
        }
    }
    vs[0] = 11;
    random_shuffle(vs.begin(), vs.end());
    
    for (int i = 0; i < 300; i++) {
        for (int j = 0; j < 300; j++) {
            cout << vs[pos++] << " ";
        }
        cout << "\n";
    }
}

int main(void) {
    //gen(); return 0;
    scanf("%d%d%d", &N, &M, &P);

    int ans = INF;

    set<pair<int, pair<int, int> > > q;

    memset(dp, 63, sizeof(dp));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &V[i][j]);
            buff[V[i][j]].push_back(make_pair(i, j));

            if (V[i][j] == 1) {
                dp[1] = min(dp[1], dist(0, 0, i, j));
                q.insert(make_pair(dist(0, 0, i, j), make_pair(i, j)));                
            }
        }
    }

    while (!q.empty()) {
        int ds = (*q.begin()).first;
        int r = (*q.begin()).second.first;
        int c = (*q.begin()).second.second;
        q.erase(q.begin());

        //if (ds > dp[V[r][c]]) continue;
        
        if (V[r][c] == P) {
            chmin(ans, dp[P]);
        }

        for (int i = 0; i < (int) buff[V[r][c] + 1].size(); i++) {
            int nr = buff[V[r][c] + 1][i].first;
            int nc = buff[V[r][c] + 1][i].second;
            
            if (dp[V[nr][nc]] > ds + dist(r, c, nr, nc)) {
                dp[V[nr][nc]] = ds + dist(r, c, nr, nc);
                q.insert(make_pair(dp[V[nr][nc]], make_pair(nr, nc)));
            }
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
