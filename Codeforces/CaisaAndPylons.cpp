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

const int MAXN = 100005;

int N;
int P[MAXN];

int main(void) {
	cin >> N;

	P[0] = 0;

	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}

	int ans = INT_MAX;

	int l = 0, h = 5 * MAXN;

	for ( ; l <= h; ) {
		int m = (l + h) / 2;	
		
		int energy = 0;
		
		P[0] = m;

		for (int i = 0; i < N; i++) {
			energy += (P[i] - P[i + 1]);
			if (energy < 0) break;
		}

		if (energy >= 0) {
			chmin(ans, m);
			h = m - 1;
		} else {
			l = m + 1;
		}
	}

	cout << ans << "\n";

    return 0;
}
