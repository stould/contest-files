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

int N, A, B, C, M;

int main(void) {
	freopen("cowroute.in", "r", stdin);
	freopen("cowroute.out", "w", stdout);
	
	cin >> A >> B >> N;

	int ans = INT_MAX;
	
	for (int i = 0; i < N; i++) {
		cin >> C >> M;

		int Ci;

		bool seenA = false;
		bool ok = false;
		
		for (int j = 0; j < M; j++) {
			cin >> Ci;

			if (Ci == A) {
				seenA = true;
			} else if (Ci == B) {
				if (seenA) {
					ok = true;
				}
			}
		}

		if (ok) ans = min(ans, C);
	}

	if (ans == INT_MAX) {
		ans = -1;
	}

	cout << ans << endl;
	
    return 0;
}
