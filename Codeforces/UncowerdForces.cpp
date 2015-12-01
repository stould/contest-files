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

int M[6], W[6], H[6];
int P[5] = {500, 1000, 1500, 2000, 2500};

int main(void) {
	double ans = 0;
	
	for (int i = 0; i < 5; i++) {
		cin >> M[i];
	}

	for (int i = 0; i < 5; i++) {
		cin >> W[i];
	}

	for (int i = 0; i < 5; i++) {
		double A = P[i] * (double) 0.3;
		double B = (1.0 - (M[i] / (double) 250.0)) * P[i] - 50.0 * W[i];

		ans += max(A, B);
	}

	cin >> H[0] >> H[1];

	ans += 100 * H[0] - 50 * H[1];

	cout << fixed << setprecision(0) << ans << "\n";

	return 0;
}
