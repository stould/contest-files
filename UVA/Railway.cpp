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

double XM, YM;
double X[10005], Y[10005];
int N;

int main(void) {
	for ( ; scanf("%lf%lf", &XM, &YM) == 2; ) {
		scanf("%d", &N);

		double ans = 999999999999.0;

		for (int i = 0; i < N + 1; i++) {
			scanf("%lf%lf", &X[i], &Y[i]);

			if (i > 0) {
				double A = (Y[i] - Y[i - 1]) / (X[i] - X[i - 1]);
				double B = Y[i] - A * X[i];

				double dst = abs(XM * A + (-B) * YM) / (sqrt(A*A + B*B));

				ans = min(ans, dst);				
			}
		}
		printf("%.5lf\n", ans);
	}
    return 0;
}
