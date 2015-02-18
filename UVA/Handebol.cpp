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

int N, M;

int main(void) {	
	for ( ; scanf("%d%d", &N, &M) == 2; ) {
		int ans = 0;
		
		for (int i = 0; i < N; i++) {
			int P;
			bool ok = true;
			for (int j = 0; j < M; j++) {
				cin >> P;
				if (P == 0) {
					ok = false;
				}
			}
			if (ok) ans += 1;
		}
		
		cout << ans << "\n";
	}
    return 0;
}
