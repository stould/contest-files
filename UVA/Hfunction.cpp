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

int T, N;

int main(void) {
	scanf("%d", &T);

	for ( ; T--; ) {
		scanf("%d", &N);

		if (N < 1) {
			printf("%d\n", 0);
			continue;
		}
		
		Int len = (Int) sqrt(N), last = N;
		Int sum = 0LL;
		
		for (int i = 1; i <= len; i++) {
			sum += (Int) (N / i);
			sum += (i - 1) * (Int) (last - N / i);
			last = N / i;
		}
		
		if (N / len > len) sum += len;
		
		printf("%lld\n", sum);
	}

    return 0;
}
