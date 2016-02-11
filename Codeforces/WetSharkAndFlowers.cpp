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

const Int MAX_V = 1000000000LL;
const int MAXN = 100005;

int N, P;
int L[MAXN], R[MAXN];
double ep[MAXN];

int valid(int i, int j) {
	return max(0, j / P - (i - 1) / P);
}

int main(void) {
	cin >> N >> P;

	for (int i = 0; i < N; i++) {
		cin >> L[i] >> R[i];

		ep[i] = valid(L[i], R[i]) / (double) (R[i] - L[i] + 1);
	}

	double ans = 0.0;

	for (int i = 0; i < N; i++) {
		ans += 2000 * (1 - ((1 - ep[i]) * (1 - ep[(i + 1) % N])));
	}
	
	cout << fixed << setprecision(6) << ans << endl;

	return 0;
}
