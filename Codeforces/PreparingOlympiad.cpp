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

int N, L, R, X;
int C[16];

int main(void) {
	cin >> N >> L >> R >> X;

	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}

	sort(C, C + N);

	int ans = 0;

	for (int x = 1; x < (1 << N); x++) {
		if (__builtin_popcount(x) < 2) continue;
		vector<int> pr;

		for (int i = 0; i < N; i++) {
			if (x & (1 << i)) {
				pr.push_back(C[i]);
			}
		}

		bool ok = true;

		int s = 0;

		for (int i = 0; i < (int) pr.size(); i++) {
			s += pr[i];			
		}
		if (pr[pr.size() - 1] - pr[0] < X) {
			ok = false;
		}
		if (s < L or s > R) {
			ok = false;
		}
		if (ok) ans += 1;
	}
	
	cout << ans << endl;
	
	return 0;
}
