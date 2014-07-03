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

int N, T, pz;
vector<int> primes;

bool u[310];
bool dp[1005][15][150];
int path[15];

bool func(int n, int t, int id) {
	if (id >= pz) {
		return false;
 	} else if (t == T) {
		return n == N;
	} else if (n >= N) {
		return false;
	} else {
		bool& ans = dp[n][t][id];

		if (ans) {
			path[t] = primes[id];
			if (func(n + primes[id], t + 1, id + 1)) {
				return true;
			}
			if (func(n, t, id + 1)) {
				return true;
			}
		}
		return ans = false;
	}
}

bool cmp(int a, int b) {
	stringstream sa;
	stringstream sb;
	sa << a;
	sb << b;
	return sa.str() < sb.str();
}

int main(void) {
	int t = 1;

	memset(u, true, sizeof(u));

	for (int i = 2; i <= sqrt(300); i++) {
		if (u[i]) {
			for (int j= i + i; j < 300; j += i) {
				u[j] = false;
			}
		}
	}
	primes.push_back(2);
	for (int i = 3; i < 300; i++) {
		if (u[i]) {
			primes.push_back(i);
			primes.push_back(i);
		}
	}
	pz = (int) primes.size();

	sort(primes.begin(), primes.end(), cmp);
    for ( ; scanf("%d%d", &N, &T) == 2 && N + T != 0; ) {
		memset(dp, true, sizeof(dp));
		bool outcome = func(0, 0, 0);

		printf("CASE %d:\n", t++);

		if (outcome) {
			for (int i = 0; i < T; i++) {
				printf("%d", path[i]);
				if (i != T - 1) printf("+");
			}
			puts("");

		} else {
			printf("No Solution.\n");
		}
    }
    return 0;
}
