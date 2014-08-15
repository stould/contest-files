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

int A, B, C;

int func(int a, int b, int c) {
	return (a*a + b*b) == c*c;
}

int main(void) {
	for ( ; scanf("%d%d%d", &A, &B, &C) == 3; ) {
		int G = gcd(A, gcd(B, C));
		
		
		if (func(A, B, C) or func(A, C, B) or func(B, C, A)) {
			if (G == 1) {
				puts("tripla pitagorica primitiva");
			} else {
				puts("tripla pitagorica");
			}
		} else {
			puts("tripla");
		}
	}
    return 0;
}
