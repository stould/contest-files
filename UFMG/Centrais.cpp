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

int N;

int main(void) {
	for ( ; scanf("%d", &N) == 1; ) {
		if (N == 1) {
			printf("1\n");
		} else {
			for (int i = 0; i <= N; i++) {
				tree[i].clear();
			}
			for (int i = 0; i < N - 1; i++) {
				int A, B;
				scanf("%d%d", &A, &B);
			}
			
		}
	}
	   
    return 0;
}
