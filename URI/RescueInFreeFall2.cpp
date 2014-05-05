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

const int MAXN = 550;
const double INF = 10101010101.0;

int T, N;
int X[MAXN], Y[MAXN];

double G[MAXN][MAXN];
int sel[MAXN];
bool vis[MAXN];
double min_c[MAXN];

double func(void) {
	fill(vis, vis + N + 1, false);
	fill(sel, sel + N + 1, -1);
	fill(min_c, min_c + N + 1, INF);

	double ans = 0.0;
	min_c[0] = 0;

	for (int i = 0; i < N; i++) {
		int next = -1;

		for (int j = 0; j < N; j++) {
			if (!vis[j] && (next == -1 || min_c[j] < min_c[next])) {
				next = j;					
			}
		}
		vis[next] = true;
		if (sel[next] != -1) {
			ans += min_c[next];
		}
		for (int j = 0; j < N; j++) {
			if (G[next][j] < min_c[j]) {
				min_c[j] = G[next][j];
				sel[j] = next;
			}
		}
	}
	return ans / 100.0;
}

int main(void) {
	cin >> T;

	for ( ; T--; ) {
		cin >> N;

		memset(G, 63, sizeof(63));

		for (int i = 0; i < N; i++) {
			cin >> X[i] >> Y[i];
			for (int j = 0; j < i; j++) {
				double d = hypot(X[i] - X[j], Y[i] - Y[j]);
				G[i][j] = G[j][i] = d;
			}
		}
		cout << fixed << setprecision(2) << func() << "\n";
	}
    return 0;
}
