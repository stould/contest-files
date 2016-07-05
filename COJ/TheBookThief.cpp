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

Int N;

Int sum(Int x) {
	return x * (x + 1) / 2;
}

pair<int, int> func(int x) {
	Int all = sum(x);
	
	if (all > N) {
		if (all - N <= x) {
			return make_pair(all - N, x);
		} else {
			return make_pair(-2, -2);
		}
	} else {
		return make_pair(-1, -1);
	}
}

int main(void) {
	for ( ; scanf("%lld", &N) && N != 0; ) {
		pair<int, int> ans = make_pair(-1, -1);
		
		int poss = (int) sqrt(N);

		int l = poss, h = 1000000, m;

		for ( ; l <= h; ) {
			m = (l + h) / 2;

			if (func(m).first == -1) {
				l = m + 1;
			} else if (func(m).first == -2) {
				h = m - 1;
			} else {
				poss = m;
				break;
			}
		}
		
		ans = func(poss);
				
		printf("%d %d\n", ans.first, ans.second);
	}
	return 0;
}
