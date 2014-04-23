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

const int MOD = 1000000007;
const int MAXN = 100005;

int T, N;
string S;

struct MyCmp {
	bool operator()(pair<int, int> x, pair<int, int> y) {
		int dx = abs(x.first - N / 2);
		int dy = abs(y.first - N / 2);

		if (dx != dy) {
			return dx < dy;
		} else {
			return x.second > y.second;
		}
	}
};

int main(void) {
	//	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> S;
		N = (int) S.size();

		Int ans = 0LL, b = 1LL;
		int p1 = N / 2, p2 = N / 2;
		bool odd = true;

		if (N % 2 == 0) {
			p1 -= 1;
			odd = false;
		}
		
		for (int i = 0; i < N; i++) {
			if (odd) {
				odd = false;
				if (p1 >= 0) {
					cout << p1 << "\n";
					ans = (ans + (b * (S[p1] - '0')) % MOD) % MOD;
					b = (b * 2LL) % MOD;					
					p1 -= 1;
				}
			} else {
				odd = true;
				if (p2 < N) {
					cout << p2 << "\n";
					ans = (ans + (b * (S[p2] - '0')) % MOD) % MOD;
					b = (b * 2LL) % MOD;
					p2 += 1;
				}
			}
		}

		cout << "Case #" << t << ": " << ans << "\n";
	}

    return 0;
}
