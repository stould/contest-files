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

char S[MAXN];
int N;
int C[MAXN], O[MAXN];

int main(void) {
	freopen("cow.in", "r", stdin);
	freopen("cow.out", "w", stdout);
	
	scanf("%d%s", &N, S);

	Int ans = 0LL;
	
	for (int i = 0; i < N; i++) {
		if (S[i] == 'C') {
			C[i] += 1;
		}
		if (i > 0) {
			C[i] += C[i - 1];
		}
		if (S[i] == 'O') {
			O[i] += C[i];
		}
		if (i > 0) {
			O[i] += O[i - 1];
		}
		if (S[i] == 'W') {
			if (i > 0) {
				ans += O[i];
			}
		}
	}

	printf("%lld\n", ans);
	
    return 0;
}
