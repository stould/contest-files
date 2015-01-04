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

const int MAXN = 12;

int N;
int P[MAXN];
int L[MAXN];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	int longest = 1;

	for (int i = 0; i < N; i++) {
		int l = 1, h = longest, m;

		for ( ; l <= h; ) {
			m = (l + h) / 2;

			if (P[i] > P[L[m]]) {
				l = m + 1;
			} else {
				h = m - 1;
			}
		}

		L[l] = i;
		
		if (l > longest) {
			longest = l;
		}
	}
	
	cout << longest << "\n";

    return 0;
}
