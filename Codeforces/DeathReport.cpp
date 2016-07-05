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

string S;

int main(void) {
	cin >> S;

	uInt ans = 1ULL;
	uInt asL = 0;
	int toGo = 1;

	bool seen = false;

	for (int i = 0; i < (int) S.size(); i++) {
		if (S[i] == '.') {
			seen = true;
			continue;
		}
		asL = asL * 10ULL + (S[i] - '0');
		if (seen) {
			toGo += 1;
		}
	}
	
	int tw = 0, fi = 0;

	while (asL % 2LL == 0) {
		tw += 1;
		asL /= 2LL;
	}
	while (asL % 5LL == 0) {
		fi += 1;
		asL /= 5LL;
	}
	//cout << tw << " " << fi << "\n";
	while (tw <= toGo) {
		tw += 1;
		ans *= 2LL;
	}
	while (fi <= toGo) {
		fi += 1;
		ans *= 5LL;
	}

	cout << ans << "\n";
	return 0;
}
