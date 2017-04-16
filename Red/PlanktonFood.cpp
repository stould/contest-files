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

const int MAXN = 5050;
const double INF = 10000101001010.0;
const double EPS = 1e-6;

int T, N, F0, F1;

vector<pair<int, double> > edges[MAXN];
double dp[MAXN][2 * MAXN];
int memo[MAXN][2 * MAXN];
int id = 1;

double func(int pos, int len) {
    if (len < 0) return -INF;
    if (pos == F1) {
        return 0;
    } else {
        double& ans = dp[pos][len];
        
        if (memo[pos][len] != id) {
            ans = -INF;
            
            for (int i = 0; i < (int) edges[pos].size(); i++) {
                double next = func(edges[pos][i].first, len - 1) + edges[pos][i].second;
                ans = max(ans, next);
            }
        }
        
        return ans;
    }
}
int main(void) {
    while (cin >> T >> N >> F0 >> F1) {
        if (T + N + F0 + F1 == 0) break;

        for (int i = 0; i < MAXN; i++) {
            edges[i].clear();
        }
        
        for (int i = 0; i < T; i++) {
            int A, B;
            double D;
            
            cin >> A >> B >> D;
            edges[A].push_back(make_pair(B, D));
        }

        bool fine = false;

        double ans = func(F0, N);
        
        if (ans + EPS > 0) {
            fine = true;
        }
        if (fine) {
            cout << "TRUE" << endl;
        } else {
            cout << "FALSE" << endl;
        }
        id++;
    }
    return 0;
}
