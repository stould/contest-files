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

int T;
int A, B, K;

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> A >> B >> K;
		set<pair<int, int> > s;
		for (int i = 0; i < A; i++) {
			for (int j = 0; j < B; j++) {
				if ((i & j) < K) {
					s.insert(make_pair(i, j));
				}
			}
		}

		cout << "Case #" << t << ": " << s.size()<< "\n";
	}
    return 0;
}
