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

const int MAXN = 1000007;
int N, K;

int P[MAXN];

int main(void) {
	N = in();
	K = in();

	for (int i = 0; i < N; i++) {
		P[i] = in();
	}

	int id = 0, inv = 0;
	
	for (int i = 0; i < N - K; i++) {
		int m = INT_MAX;
		int curr_inv = 0;
		
		for (int j = 0; j < K; j++) {
			chmin(m, P[i + j]);

			if (P[i] > m) {
				curr_inv += 1;
			}
		}
		if (curr_inv > inv) {
			inv = curr_inv;
			id = i;
		}
	}

	sort(P + id, P + id + K);
	
	for (int i = 0; i < N; i++) {
		printf("%d ", P[i]);
	}

	printf("\n");
	
	return 0;
}
