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
int A, B;

int main(void) {
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++) {
		scanf("%d%d", &A, &B);

		if ((A < 0 && B < 0) || (A > 0 && B > 0)) {
			printf("%d\n", B - A);
		} else {
			printf("%d\n", B - 1 + (-A));
		}
		
	}
    return 0;
}
