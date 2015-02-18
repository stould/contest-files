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

const int MAXN = 10000005;

int N, M, A, B, C;
bool used[MAXN];

bool func(int a, int b) {
	for (int i = a; i <= b; i++) {
		if (used[i]) return false;
		used[i] = true;
	}
	return true;
}


int main(void) {
	for ( ; scanf("%d%d", &N, &M) && !(N == 0 && M == 0); ) {
		memset(used, false, sizeof(used));

		bool ok = true;

		for (int i = 0; i < N; i++) {
			scanf("%d%d", &A, &B);
			
			if (ok && !func(A, B - 1)) ok = false;
		}
		for (int i = 0; i < M; i++) {
			scanf("%d%d%d", &A, &B, &C);
			for (int j = 0; j * C + A <= 1000000; j++) {
				if (ok && !func(j * C + A, min(1000000, j * C + B - 1))) {
					ok = false;
				}
			}
		}
		puts(ok ? "NO CONFLICT" : "CONFLICT");
	}
    return 0;
}
