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

const Int INF = 10100101010010100LL;

int A, B, N;
string S, G;

int main(void) {
	for ( ; cin >> A >> B >> S; ) {
		N = S.size();

		Int ans = 0;
		int last = -1;

		for (int i = 0; i < N; i++) {
			if (S[i] == 'B') {
				if (last != i - 1) {
					ans += min(A, B * (i - last + 1));
				}
				last = i;
			}
		}
		
		cout << ans << "\n";
	}
    return 0;
}
