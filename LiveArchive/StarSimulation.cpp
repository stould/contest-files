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
const double EPS = 1e-7;

int N;
double K;
int X[MAXN], Y[MAXN], Z[MAXN];

double dist(int i, int j) {
	double dx = X[i] - X[j];
	double dy = Y[i] - Y[j];
	double dz = Z[i] - Z[j];

	return dx * dx + dy * dy + dz * dz;
}
			   
int main(void) {
	while (cin >> N >> K && N != 0) {
		int ans = 0;
		for (int i = 0; i < N; i++) {
			cin >> X[i] >> Y[i] >> Z[i];
			for (int j = 0; j < i; j++) {
				if (dist(i, j) + EPS <= K * K) {
					ans += 1;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
