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
typedef unsigned uint;
const double INF = 101010101000.0;
int N;
int X[1010], Y[1010];
int T;
double G[505][505];

bool used[550];
double min_e[550], sel_e[550];
int main(void) {
	cin >> T;
	for ( ; T-- ; ) {
		cin >> N;
		memset(G, 63, sizeof(G));
		double ans = 0.0;
		for (int i= 1; i <= N; i++) {
			cin >> X[i] >> Y[i];
			for (int j = 1; j < i; j++) {
				double d = hypot(X[i] - X[j], Y[i] - Y[j]);
				G[i][j] = G[j][i] = d;
			}
		}
        for(int i = 1; i <= N; i++) {
            used[i] = false;
            min_e[i] = INF;
            sel_e[i] = -1.0;
        }
        min_e[1] = 0.0;
        for (int i = 1; i <= N; ++i) {
            int v = -1;
            for (int j = 1; j <= N; ++j) {
                if (!used[j] && (v == -1 || min_e[j] < min_e[v])) {
                    v = j;
                }
            }
            used[v] = true;
            if (sel_e[v] != -1) {
				ans += min_e[v];
            }
            for (int j = 1; j <= N; j++)
                if (G[v][j] < min_e[j]) {
                     min_e[j] = G[v][j];
                    sel_e[j] = v;
                }
        }
		cout << fixed << setprecision(2) << ans / 100.0 << "\n";
	}
    return 0;
}
