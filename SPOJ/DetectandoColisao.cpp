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

int XA[2], XB[2], YA[2], YB[2];

int main(void) {
	for (int i = 0; i < 2; i++) {
		scanf("%d%d%d%d", &XA[i], &YA[i], &XB[i], &YB[i]);
	}
	if (XA[1] >= XA[0] && XA[1] <= XB[0]) {		
		
	}
	
    return 0;
}
