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

int N, K;
int L[MAXN];
int C[MAXN];

int main(void) {
	for ( ; cin >> N >> K; ) {
		for (int i = 0; i < N; i++) {
			cin >> L[i];
		}

		int sum = 0;

		set<int> all;
		
		for (int i = 0; i < K; i++) {
			cin >> C[i];
		}
		for (int i = 0; i < K; i++) {

			sum += L[C[i] - 1];

			all.insert(C[i]);

			if (all.size() == N) {
				break;
			}
		}

		if (all.size() == N) {
			cout << sum << endl;
		} else {
			cout << -1 << endl;
		}
	}
    return 0;
}
