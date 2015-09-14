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

int N, X;

int main(void) {
	cin >> N >> X;

	int ans = 0;
	int sq = (int) sqrt(X);

	for (int i = 1; i <= sq; i++) {
		if (X % i == 0) {
			int s = 0;
			
			if (i <= N && X / i <= N) {
				ans += 1;
				s += 1;
			}
			if (X / i <= N && i <= N) {
				ans += 1;
				s += 1;
			}

			if (X / i == i && s == 2) {
				ans -= 1;
			}			
		}
	}

	cout << ans << endl;
	
	return 0;
}
