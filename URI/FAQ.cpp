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

int N, K;
int P[110];

int main(void) {
	for ( ; cin >> N >> K && N + K != 0; ) {
		memset(P, 0, sizeof(P));
		set<int> s;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			int p;
			cin >> p;

			P[p] += 1;
			if (P[p] >= K && !s.count(p)) {
				ans += 1;
				s.insert(p);
			}
		}
		cout << ans << "\n";
	}
    return 0;
}
