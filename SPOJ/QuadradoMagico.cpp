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

const int MAXN = 1010;

int N;
int L[MAXN], C[MAXN];
int seen[MAXN * MAXN];

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int P;
			cin >> P;

			L[i] += P;
			C[j] += P;

			if (P >= 1 && P <= N * N) {			
				seen[P] = 1;
			}
		}
	}

	bool ok = true;

	for (int i = 1; i < N; i++) {
		if (L[i] != L[i - 1]) ok = false;
		if (C[i] != C[i - 1]) ok = false;
	}

	for (int i = 1; i <= N * N; i++) {
		if (!seen[i]) ok = false;
	}

	if (ok) {
		cout << L[0] << endl;
	} else {
		cout << 0 << endl;
	}
	
    return 0;
}
