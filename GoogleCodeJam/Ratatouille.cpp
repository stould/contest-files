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

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 55;
const double EPS = 0;
const int MAX_QT = 100;

int T, N, P;
long long C[MAXN];
long long S[MAXN][MAXN];
bool ok[MAXN][MAXN];
bool active[MAXN][MAXN];
int L[MAXN][MAXN];
int R[MAXN][MAXN];

bool valid(long long a, long long b) {
    double perc = a / (double) b * 10000.0;

    if (perc + EPS >= 9000 && perc - EPS <= 11000) {
        return true;
    }
    return false;
}

int main(void) {
    cin >> T;
    int ml = 0;
    for (int t = 1; t <= T; t++) {
        cin >> N >> P;

        memset(ok, 0, sizeof(ok));
        memset(active, 0, sizeof(active));
        memset(L, 62, sizeof(L));
        memset(R, -1, sizeof(R));

        for (int i = 0; i < N; i++) {
            cin >> C[i];
        }

        map<int, set<int> > s[MAX_QT + 1];
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < P; j++) {
                cin >> S[i][j];

                for (int k = 1; k <= MAX_QT; k++) {
                    if (valid(S[i][j], C[i] * (long long) k)) {
                        ok[i][j] = 1;

                        s[k][i].insert(j);
                        
                        L[i][j] = min(L[i][j], k);                        
                        R[i][j] = max(R[i][j], k);
                        ml = max(ml, R[i][j]);
                    }                    
                }
            }
        }
        //cout << ml << endl;
        int ans = 0;

        for (int qt = 1; qt <= MAX_QT; qt++) {
            int check = INT_MAX;
            for (int i = 0; i < N; i++) {
                check = min(check, (int) s[qt][i].size());
            }
            ans += check;
        }
        
        cout << "Case #" << t << ": ";
        cout << ans << "\n";
    }
    return 0;
}
