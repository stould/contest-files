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

const int MAXN = 1000001;
int X, N;
int P[MAXN];
int main(void) {
	for ( ; cin >> X >> N; ) {
		X *= 10000000;
		map<int, int> mp;
		for (int i = 0; i < N; i++) {
			cin >> P[i];
			mp[P[i]] += 1;
		}
		sort(P, P + N);
		bool ok = false;
		for (int i = 0; i < N; i++) {
			int p = X - P[i];
			if (binary_search(P, P + N, p)) {
				if (P[i] == p && mp[P[i]] == 1) continue;
				ok = true;
				printf("SIM %d %d\n", P[i], p);
				break;
			}
		}
		if (!ok) {
			printf("PERIGO\n");
		}
	}
    return 0;
}
