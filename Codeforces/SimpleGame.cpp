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
typedef unsigned uint;

int N, M;

int main(void) {
	cin >> N >> M;

	if (N == 1) {
		cout << 1 << "\n";
		return 0;
	}

	if (M - 1 >= N - M) {
		if (M - 1 >= 1) {
			cout << M - 1 << "\n";
		} else {
			cout << M + 1 << "\n";
		}
	} else {
		if (M + 1 <= N) {
			cout << M + 1 << "\n";
		} else {
			cout << M - 1 << "\n";
		}
	}
	
	return 0;
}
