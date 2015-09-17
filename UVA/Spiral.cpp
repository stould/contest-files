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

typedef unsigned long long Int;
typedef long long int uInt;
typedef unsigned uint;

uInt N, B;

uInt func(uInt diag) {
	uInt aN = N - diag * 2;
	return 4 * (diag * (N + aN) / 2) + 1;
}

int main(void) {
	while (cin >> N >> B) {
		uInt l = 1, h = (N + 1) / 2, m;
		uInt best = 0;
		
		while (l <= h) {
			m = l + (h - l) / 2;
			
			uInt seen = func(m - 1);

			if (seen > B) {
				h = m - 1;
			} else {
				best = max(best, m);
				l = m + 1;
			}
		}

		uInt r = best, c = best;
		uInt seen = func(best - 1);
		uInt toAdd = N - (best - 1) * 2 - 1;

		for (int i = 0; i < 4; i++) {
			if (seen == B) break;
			
			uInt sd = 0ULL;
			
			if (seen + toAdd <= B) {
				sd = toAdd;
			} else {
				sd = B - seen; 
			}
			
			seen += sd;
						
			if (i == 0) {
				c += sd;
			} else if (i == 1) {
				r += sd;
			} else if (i == 2) {
				c -= sd;
			} else {
				r -= sd;
			}
		}

		cout << r << " " << c << endl;
	}
	
	return 0;
}
