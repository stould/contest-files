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

const int MAXN = 8;

int N;
int P[MAXN];

Int dp[4010][1 << 8];

Int func(int f, int mask) {
	if (mask == (1 << N) - 1) {
		return 1;
	} else {
		Int& ans = dp[f][mask];

		if (ans == -1) {
			ans = 0LL;

			for (int i = 0; i < N; i++) {
				if (!(mask & (1 << i))) {
					ans += func(f + P[i], mask | (1 << i));

					if (f - P[i] >= 0) {
						ans += func(f - P[i], mask | (1 << i));
					}
				}
			}
		}
		
		return ans;			
	}
}

int main(void) {
	cin >> N;

	int sum = 0;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
		sum += P[i];
	}

	memset(dp, -1, sizeof(dp));

	Int poss = func(0, 0);

	cout << poss << " " << sum << "\n";

	if (sum >= poss) {
		cout << "Got no way out!\n";
	} else {
		cout << "We will win!\n";
	}
	
	return 0;
}
