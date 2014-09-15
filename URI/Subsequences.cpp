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

int T, Q;
string S, P;

int main(void) {
	cin >> T;

	for ( ; T--; ) {
		cin >> S >> Q;
		int N = (int) S.size();
		for ( ; Q--; ) {
			cin >> P;
			int M = (int) P.size();
			
			int ia = 0, ib = 0;

			while (ia < N && ib < M) {
				if (S[ia] == P[ib]) {
					ib++;
				}
				ia++;
			}
			if (ib == M) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
	}
    return 0;
}
