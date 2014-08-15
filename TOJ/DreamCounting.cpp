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
int cnt[11];

int main(void) {
	scanf("%d%d", &N, &M);
	
	for (int i = N; i <= M; i++) {
		int c = i;
		for ( ; c > 0; c /= 10) {
			cnt[c % 10] += 1;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (i) printf(" ");
		printf("%d", cnt[i]);
	}
	printf("\n");
    return 0;
}
