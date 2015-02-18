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

const int MAXN = 500005;

int D, K;
Int pos[MAXN];

int main(void) {
	for ( ; scanf("%d%d", &D, &K) == 2 && D != 0 && K != 0; ) {
		memset(pos, 0, sizeof(pos));
		int ans = 0;

		for (int i = 0; i < K; i++) {
			pos[i] += (Int) (i + 1) * D * D;
			ans += pos[i] % 10;
			pos[i + 1] += pos[i] / 10;			
		}
		int p = 1;
		for (int i = K; i <= 2 * K; i++) {
			pos[i] += (Int) (K - p) * D * D;
			if (pos[i] <= 0) break;
			ans += pos[i] % 10;
			pos[i + 1] += pos[i] / 10;
			p++;
		}
		for (int i = 2 * K + 1; pos[i] != 0; i++) {
			ans += pos[i] % 10;
			pos[i + 1] += pos[i] / 10;
		}
		printf("%d\n", ans);
	}
    return 0;
}
