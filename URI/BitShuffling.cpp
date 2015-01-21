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

Int N, K;

int main(void) {
	for ( ; cin >> N >> K; ) {
		if (N == 0 && K == 0) break;
		
		int A, B;
		
		Int S = N;
		Int L = N;
		
		for (int i = 0; i < K; i++) {
			cin >> A >> B;

			Int sa = N & (1 << A);
			Int sb = N & (1 << B);
			
			if (sa > 0) sa = 1;
			if (sb > 0) sb = 1;

			if (sa != sb) {
				N ^= (1LL << A);
				N ^= (1LL << B);
			}
			S = min(S, N);
			L = max(L, N);						
		}
			
		cout << N << " " << L << " " << S << endl;
	}
	
    return 0;
}
