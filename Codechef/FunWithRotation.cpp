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

const int MAXN = 100005;

int N, M, D;
int P[MAXN];
char T;

int main(void) {
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &P[i]);
	}

	int sp = 0;

	for ( ; M--; ) {
		scanf(" %c%d", &T, &D);

		if (T == 'C') {			
			sp = (sp + D) % N;
		} else if (T == 'A') {
			sp = (((sp - D) % N) + N) % N;
		} else {
			D -= 1;
			printf("%d\n", P[(((D + sp) % N) + N) % N]);
		}
	}

    return 0;
}
