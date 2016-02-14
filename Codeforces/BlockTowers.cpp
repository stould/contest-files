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

const Int INF = 10010100101010100LL;

Int N, M;

int main(void) {
	cin >> N >> M;
	
	Int l = 0, h = 10000000, m;
	Int ans = INF;

	while (l <= h) {
		m = (l + h) / 2;

		int x = m / 6;
		int a = m / 2;
		int b = m / 3;
		
		if (a >= N && b >= M && a + b - x >= N + M) {
			ans = m;
			h = m - 1;
		} else {
			l = m + 1;
		}
	}

	cout << ans << "\n";

	return 0;
}
