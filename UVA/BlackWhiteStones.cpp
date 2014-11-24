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

const int INF = INT_MAX / 3;

int A, B, N;
string S, G;
map<string, int> dp;
map<string, bool> memo;

int func(string s) {
	if (s == G) {
		return 0;
	} else {
		if (memo[s] == false) {
			memo[s] = true;

			int ans = INF;

			for (int i = 0; i < N; i++) {
				if (s[i] == 'W') {
					bool ok = true;

					for (int j = i + 1; j < N; j++) {
						if (s[j] == 'B') {
							swap(s[i], s[j]);
							ans = min(ans, ((i == j - 1) ? B : A) + func(s));
							swap(s[i], s[j]);
						}
					}
				}
			}
			dp[s] = ans;
		}

		return dp[s];
	}
}

int main(void) {
	for ( ; cin >> A >> B; ) {
		cin >> S;
		G = S;
		N = S.size();

		sort(G.begin(), G.end());

		memo.clear();

		cout << func(S) << "\n";
	}
    return 0;
}
