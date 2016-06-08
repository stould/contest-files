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

const int MAXN = 501;

int N, K;
char S[MAXN][MAXN];
int vis[MAXN][MAXN];
int belong[MAXN][MAXN];
int comp = 1;
int cnt[MAXN * MAXN];
int sum[MAXN][MAXN];

int dx[4] = {-1, 1,  0, 0};
int dy[4] = { 0, 0, -1, 1};

void update(int r, int c, int val) {
    for (int i = r; i <= N; i += (i & -i)) {
        for (int j = c; j <= N; j += (j & -j)) {
            sum[i][j] += val;
        }
    }
}

int get(int r, int c) {
    int ans = 0;

    for (int i = r; i > 0; i -= (i & -i)) {
        for (int j = c; j > 0; j -= (j & -j)) {
            ans += sum[i][j];
        }
    }
    
    return ans;
}

int rect(int r, int c) {
    int ans = get(r + K - 1, c + K - 1);
    
    ans -= get(r - 1, c + K - 1);
    ans -= get(r + K - 1, c - 1);
    ans += get(r - 1, c - 1);
        
    return ans;
}

int dfs(int r, int c, int comp) {
    int ans = 1;

    vis[r][c] = true;
    belong[r][c] = comp;
    
    for (int i = 0; i < 4; i++) {
        int pr = r + dx[i];
        int pc = c + dy[i];
        
        if (pr >= 1 && pc >= 1 && pr <= N && pc <= N && S[pr][pc] == '.' && !vis[pr][pc]) {
            ans += dfs(pr, pc, comp);
        }
    }
    
    return ans;
}

int main(void) {
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> S[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (S[i][j] == 'X') {
                update(i, j, 1);
            }
            if (S[i][j] == 'X') {
                belong[i][j] = -1;
            }
            if (S[i][j] == '.') {
                if (!vis[i][j]) {
                    int ans = dfs(i, j, comp);
                    
                    cnt[comp] = ans;
                    comp++;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << belong[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i + K - 1 <= N && j + K - 1 <= N) {
                set<int> sided;
                
                for (int k = 0; k < K; k++) {
                    if (i - 1 >= 1) {
                        if (S[i - 1][k] == '.') {
                            sided.insert(belong[i - 1][k]);
                        }
                    }
                    if (i + K <= N) {
                        if (S[i + K][k] == '.') {
                            sided.insert(belong[i + K][k]);
                        }
                    }
                    if (j - 1 >= 1) {
                        if (S[k][j - 1] == '.') {
                            sided.insert(belong[k][j - 1]);
                        }
                    }
                    if (j + K <= N) {
                        if (S[k][j + K] == '.') {
                            sided.insert(belong[k][j + K]);
                        }
                    }                    

                    for (int l = 0; l < K; l++) {
                        if (S[i + k][j + l] == '.') {
                            sided.insert(belong[i + k][j + l]);
                        }                                                       
                    }
                }

                int curr = rect(i, j);
                cout << i << " " << j << " " << rect(i, j) << "\n";
                for (auto it: sided) {
                    curr += cnt[it];
                    cout << it << "\n";
                }
                
                chmax(ans, curr);
            }
        }
    }

    cout << ans << "\n";
    
    return 0;
}
