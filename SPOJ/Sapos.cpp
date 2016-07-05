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
bool vis[MAXN][MAXN];
int P[MAXN][MAXN];

int dx[] = {0, -1, -1, 0, 1, 1,  1, 0, -1};
int dy[] = {0,  0,  1, 1, 1, 0, -1, -1, -1};

void dfs(int a, int b) {
    if (a < 0 || b < 0 || a >= N || b >= M || vis[a][b]) return;
    vis[a][b] = true;

    dfs(a + dx[P[a][b]], b + dy[P[a][b]]);    
}

int main(void) {
    int t = 1;
    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;
        memset(vis, false, sizeof(vis));
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> P[i][j];
            }
        }

        dfs(0, 0);
        bool ok = true;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!vis[i][j]) {
                    ok = false;
                }
            }
        }
        cout << "Instancia " << t++ << "\n";
        if (ok) {
            cout << "sim\n\n";
        } else {
            cout << "nao\n\n";
        }
    }
    return 0;
}
