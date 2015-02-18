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

const int MAXN = 110;

int N, T;
int P[MAXN];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	cin >> T;

	sort(P, P + N);

	int ans = 0;

	for (int i = 0; i < N; i++) {
		int j;
		for (j = i + 1; j < N; j++) {
			if (P[j] - P[i] > T) break;
			chmax(ans, j - i);
		}
	}

	cout << ans + 1<< "\n";

    return 0;
}
