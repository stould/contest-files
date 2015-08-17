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

int T;
int C, D;

int main(void) {
	cin >> T;

	while (T--) {
		cin >> C >> D;

		if (C == 0 && D == 0) {
			cout << 0 <<"\n";
		} else {
			cout << int(pow(26, C) * pow(10, D)) << "\n";
		}
	}
	return 0;
}
