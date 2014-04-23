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

const int MAXN = 100005;
const double INF = 99999999999999999.0;

int T;
double C, F, X;
double dp[MAXN];

int main(void) {
	cin >> T;
	freopen("o.ot", "w", stdout);

	for (int t = 1; t <= T; t++) {
		cin >> C >> F >> X;


		double best = INF, curr = 0.0, farm = 2.0;		

		for (int i = 0; i <= X; i++) {
			best = min(best, curr + X / farm);

			curr += (C / farm);
			farm += F;
		}

		printf("Case #%d: %.7lf\n", t, best);
	}
    return 0;
}
