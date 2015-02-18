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

int P, Q, L, R;
pair<int, int> A[55], B[55];

bool fit(pair<int, int> a, pair<int, int> b) {
	if (a.first <= b.first && a.second >= b.first) {
		return true;
	}
	return false;
}

int main(void) {
	scanf("%d%d%d%d", &P, &Q, &L, &R);
	
	for (int i = 0; i < P; i++) {
		scanf("%d%d", &A[i].first, &A[i].second);
	}

	for (int i = 0; i < Q; i++) {
		scanf("%d%d", &B[i].first, &B[i].second);
	}

	int ans = 0;

	for (int i = L; i <= R; i++) {
		bool ok = false;

		for (int j = 0; !ok && j < P; j++) {
			for (int k = 0; !ok && k < Q; k++) {
				pair<int, int> nq = make_pair(i + B[k].first, i + B[k].second);
				if (fit(A[j], nq) || fit(nq, A[j])) {
					ok = true;
				}
			}
		}

		if (ok) ans += 1;
	}

	cout << ans << endl;

    return 0;
}
