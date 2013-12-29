
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

const int MAXN = 10010;

int N, K, L, R;
int SA, SK;

int A[MAXN];

int main(void) {
	scanf("%d%d%d%d%d%d", &N, &K, &L, &R, &SA, &SK);

	int i;
	int buff = 1;

	for (i = 0; i < N; i++) A[i] = L;

	SK -= (K * L);
	SA -= (N * L);

	int pr = 0;

	for ( ; SK > 0; ) {
		for (i = 0; i < K && SK > 0; i++) {
			A[i] += 1;
			SK -= 1;
			pr += 1;
		}
	}
	
	SA -= pr;

	for ( ; SA > 0; ) {
		for (i = K; i < N && SA > 0; i++) {
			A[i] += 1;
			SA -= 1;
		}
	}


	for (i = 0; i < N; i++) {
		printf("%d ", A[i]);
	}

    return 0;
}
