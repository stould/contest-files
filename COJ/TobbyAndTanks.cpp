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

const int MAXN = 1010;

int N, Q;
int P[MAXN];

int main(void) {
	for ( ; scanf("%d%d", &N, &Q) == 2; ) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
		}
		for (int i = 0; i < Q; i++) {
			int K, id = 1;
			scanf("%d", &K);
			
			for (int j = 1; j < N; j++) {
				if (K - P[j] <= 0) break;
				K -= P[j];
				id = j + 1;
			}
			if (i > 0) printf(" ");
			printf("%d", id);		
			
		}
		printf("\n");
	}
    return 0;
}
