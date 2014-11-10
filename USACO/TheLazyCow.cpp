#include <iostream>
#include <cstdio>
template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 1000005;

int N, K;
int G, X;
Int P[MAXN], S[MAXN];
Int sL[MAXN], sR[MAXN];

int main(void) {
	freopen("lazy.in", "r", stdin);
	freopen("lazy.out", "w", stdout);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> G >> X;
		P[X] += G;
	}

	Int ans = 0LL;

	for (int i = 0; i <= MAXN - 5; i++) {
		S[i] = P[i];

		if (i > 0) {
			S[i] += S[i - 1];
		}

		if (i - K - 1 >= 0) {
			sL[i] = S[i] - S[i - K - 1];
		} else {
			sL[i] = S[i];
		}
	}
	
	for (int i = MAXN - 5; i >= 0; i--) {
		S[i] = P[i];
		
		if (i < MAXN - 5) {
			S[i] += S[i + 1];
		}

		if (i + K + 1 <= MAXN - 5) {
			sR[i] = S[i] - S[i + K + 1];
		} else {
			sR[i] = S[i];
		}

		sR[i] -= P[i];

		ans = max(ans, sL[i] + sR[i]);
	}

	cout << ans << "\n";

    return 0;
}
