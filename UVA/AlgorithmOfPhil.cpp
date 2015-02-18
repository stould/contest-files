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

const Int MOD = 1000000007;
const int MAXN = 100005;

int T, N;
string S;

int main(void) {
	ios_base::sync_with_stdio(false);

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> S;
		N = (int) S.size();
		int L = N;

		Int ans = 0LL, base = 1LL;
		int cnt = 0;		
		
		string sans = "";

		int p = S.size() / 2;
		int q = S.size() / 2;		

		for (int i = 0; i < N; i++) {
			if (L % 2 == 1) {
				sans += S[p];
				p++;
				q--;
				//S = S.substr(0, p) + S.substr(p + 1, S.size() - p);
			} else {
				q -= 1;

				if (S[p] >= S[q]) {
					sans += S[p];
					p++;
					//S = S.substr(0, p) + S.substr(p + 1, S.size() - p);
				} else {
					sans += S[q];
					//S = S.substr(0, q) + S.substr(q + 1, S.size() - q);
				}
			}
			L -= 1;
		}
		/*
		for (int i = sans.size() - 1; i >= 0; i--) {
			ans = (ans + base * (sans[i] - '0')) % MOD;
			base = (base * 2LL) % MOD;
		}
		*/

		cout << "Case #" << t << ": " << ans << "\n";
	}

    return 0;
}
