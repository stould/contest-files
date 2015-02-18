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
	for ( ; scanf("%d", &N) && N != 0; ) {
		int B = (int) floor(N / 90.0);
		int A = (int)  ceil(N * 7.0 / 90.0);
		
		printf("Brasil %d x Alemanha %d\n", B, A);
	}
    return 0;
}
