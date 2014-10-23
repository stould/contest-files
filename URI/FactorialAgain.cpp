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

int N;

int main(void) {
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		int ans = 0;
		int fat = 1, cnt = 2;
		
		while (N > 0) {			
			ans += (N % 10) * fat;
			fat *= cnt;
			cnt += 1;
			N /= 10;			
		}

		printf("%d\n", ans);
	}
    return 0;
}
