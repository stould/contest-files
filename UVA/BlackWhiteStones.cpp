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
string S;

int main(void) {
	for ( ; cin >> A >> B >> S; ) {
		N = S.size();

		int b = 0;
		int w = 0;
		
		Int ans = 0;

		set<int> pos;

		for (int i = 0; i < N; i++) {
			if  (S[i] == 'B') {
				b += 1;
				pos.insert(i);
			} else {
				w += 1;
			}
		}
		string F = S;
		for (int i = 0; i < b; i++) {
			if (S[i] == 'B') {
				pos.erase(i);
			} else {
				int close = *pos.begin();

				ans += min(A, (A - B) * (close - i));
				
				pos.erase(close);
			}
		}
		
		cout << ans << "\n";
	}
    return 0;
}
