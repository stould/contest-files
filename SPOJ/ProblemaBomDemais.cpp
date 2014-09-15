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

int E, T, P;

int main(void) {
	scanf("%d", &E);

	for (int i = 0; i < E; i++) {
		scanf("%d", &T);
		int curr = 0;
		for (int j = 0; j < T; j++) {
			scanf("%d", &P);
			curr += P * 3;
		}
		puts((curr > 3 * T) ? "precisa" : "nao precisa");
	}
    return 0;
}
