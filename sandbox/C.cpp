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
	
	Int h = 2 * N / 6;
	Int ans = INF;

	for (int i = 0; i <= h; i++) {
		Int A = N * 2 + 2 * i;
		Int B = M * 3 + 3 * (h - i);

		ans = min(ans, max(A, B));
	}
	
	//Int A = max(M * 3, N * 2 + 2 * ((3 * M) / 6));
	//Int B = max(N * 2, M * 3 + 3 * ((2 * N) / 6));
	
	cout << ans << "\n";

	return 0;
}
