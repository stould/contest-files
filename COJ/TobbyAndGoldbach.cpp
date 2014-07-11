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

const int MAXN = 500;

int T, N;
bool p[MAXN];
vector<int> primes;

void build(void) {
	memset(p, true, sizeof(p));
	
	for (int i = 2; i <= 400; i++) {
		if (p[i]) {
			for (int j = i * i; j <= 400; j += i) {
				p[j] = false;
			}
			primes.push_back(i);
		}
	}
}

int main(void) {
	build();
	scanf("%d", &T);

	for ( ; T--; ) {
		scanf("%d", &N);

		int ans = 0;

		for (int i = 0; i < primes.size(); i++) {
			if (N - primes[i] <= 0 || N - primes[i] < primes[i]) break;

			if (find(primes.begin(), primes.end(), N - primes[i]) != primes.end()) {
				ans += 1;
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}
