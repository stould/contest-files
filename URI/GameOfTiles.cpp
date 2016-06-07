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

const int MAXN = 51;

int N, M;
string S[MAXN];
bool is_good;
bool vis[MAXN][MAXN];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int ni, int nj, int len) {
    //cout << ni << " " << nj << "\n";
    if (is_good) return;
    
    bool ok = false;
    
    for (int i = 0; i < 4; i++) {
        int pi = ni + dx[i];
        int pj = nj + dy[i];

        if (pi >= 0 && pj >= 0 && pi < N && pj < M) {
            if (!vis[pi][pj] && S[pi][pj] == '.') {
                ok = true;
            }
        }
    }

    if (!ok) {
        if (len % 2 == 0) {
            is_good = true;
        }
    } else {
        for (int i = 0; i < 4; i++) {
            int pi = ni + dx[i];
            int pj = nj + dy[i];
            
            if (pi >= 0 && pj >= 0 && pi < N && pj < M) {
                if (!vis[pi][pj] && S[pi][pj] == '.') {
                    vis[pi][pj] = true;
                    dfs(pi, pj, len + 1);
                    vis[pi][pj] = false;
                }
            }
        }
    }
}

int main(void) {
    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;
        for (int i = 0; i < N; i++) {
            cin >> S[i];
        }

        bool one = false;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (S[i][j] == '.') {
                    memset(vis, false, sizeof(vis));
                    is_good = false;
                    dfs(i, j, 1);

                    if (!is_good) {
                        one = true;
                        goto end;
                    }
                }
            }
        }
        
    end:;
        if (one) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
     
    return 0;
}
