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
typedef unsigned uint;

const int MAXN = 102;

int N, C, S, D;
int SS[MAXN], CC[MAXN];
double dp[MAXN][MAXN][MAXN];
double dv;
int s, c, none, both;

double func(int id, int k, int r) {
    if (id == D) {
        return 2 * k == r;
    } else {
        double& ans = dp[id][k][r];

        if (ans < 0.0) {
            ans = 0;

            ans += dv * s * func(id + 1, k + 1, r);
            ans += dv * c * func(id + 1, k, r + 1);
            ans += dv * none * func(id + 1, k, r);
            ans += dv * both * func(id + 1, k + 1, r + 1);
        }
		
        return ans;
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
		
    int test = 1;
    int t;
	
    while (cin >> N && N != 0) {
        cin >> S;

        for (int i = 0; i < MAXN; i++) {
            SS[i] = CC[i] = 0;
			
            for (int j = 0; j < MAXN; j++) {
                for (int k = 0; k < MAXN; k++) {
                    dp[i][j][k] = -1.0;
                }
            }
        }

        for (int i = 0; i < S; i++) {
            cin >> t;
            SS[t] = 1;
        }

        cin >> C;
		
        for (int i = 0; i < C; i++) {
            cin >> t;
            CC[t] = 1;
        }

        none = s = c = both = 0;

        for (int i = 1; i <= N; i++) {
            if (SS[i] == 0 && CC[i] == 0) {
                none += 1;
            } else {
                if (SS[i] == 1) {
                    s += 1;
                }
                if (CC[i] == 1) {
                    c += 1;
                }
                if (SS[i] == 1 && CC[i] == 1) {
                    s -= 1;
                    c -= 1;
                    both += 1;
                }
            }
        }

        cin >> D;

        dv = 1.0 / (double) N;
		
        double ans = fabs(func(0, 0, 0));

        cout << fixed << setprecision(5) << "Case " << test++ << ": " << ans << endl;
    }
    return 0;
}
