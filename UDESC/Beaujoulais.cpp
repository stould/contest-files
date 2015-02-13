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

int N;
int A[MAXN], B[MAXN];

int main(void) {
	for ( ; scanf("%d", &N) && N != 0; ) {
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &A[i], &B[i]);		
		}

		int best = 1;
		int tmp = -1;
		
		for (int x = -10; x <= 20; x++) {
			int cnt = 0;

			for (int i = 0; i < N; i++) {
				if (A[i] <= x && B[i] >= x) {
					cnt += 1;
				}
			}
			if (cnt > 1) {
				if (cnt >= best) {
					best = cnt;
					tmp = x;
				}
			}
		}

		if (tmp == -1) {
			best = INT_MAX;
			
			for (int i = 0; i < N; i++) {
				if (A[i] < best) {
					best = A[i];
					tmp = B[i];
				}
			}
		}

		printf("%d\n", tmp);
	}
    return 0;
}
