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

const int MAXN = 2560;

int T, N;
int dp[MAXN][2];

bool p[MAXN];
vector<int> primes;

void build(void) {
	memset(p, true, sizeof(p));

	for (int i = 2; i <= 2500; i++) {
		if (p[i]) {
			primes.push_back(i);
			for (int j = i * i; j <= 2500; j += i) {
				p[j] = false;
			}
		}
	}
}

int func(int x) {
	int ans = 1;

	for (int i = 0; i < (int) primes.size() && x > 1; i++) {
		if (x % primes[i] == 0) {
			int curr = 0;
			while (x % primes[i] == 0) {
				x /= primes[i];
				curr += 1;
			}
			ans *= (curr + 1);
		}
	}
	return ans;
}

int main(void) {
	scanf("%d", &T);

	build();
	for (int i = 1; i <= 2500; i++) {
		int p = func(i);

		if (p > dp[i - 1][0]) {
			dp[i][0] = p;
			dp[i][1] = i;
		} else {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
		}

		//		printf("%d %d\n", i, p);
	}
	for ( ; T--; ) {
		scanf("%d", &N);
		printf("%d\n", dp[N][1]);
	}
    return 0;
}
