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

const int MAXM = 50005;

int T, N, C, M;
int P[MAXM];

int main(void) {
	cin >> T;

	for ( ; T--; ) {
		cin >> N >> C >> M;

		for (int i = 0; i < M; i++) {
			cin >> P[i];
		}

		sort(P, P + M);
		reverse(P, P + M);
		

		int ans = 0;

		for (int i = 0; i < M; i++) {
			int j = i, best = 0;

			while (j < M && j - i + 1 <= C) {
				chmax(best, P[j]);
				j++;
			}
			
			ans += best * 2;

			i = j - 1;
		}

		cout << ans << "\n";
	}
    return 0;
}
