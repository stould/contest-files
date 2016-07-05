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

const int MAXN = 1000005;
const int FIB_MOD = 1500;
const int DIG_MOD = 1000;

int T;
char S[MAXN];
Int fib[FIB_MOD + 2];

int len(int x) {
	int ans = 0;

	if (x == 0) {
		ans = 1;
	} else {
		while (x > 0) {
			ans += 1;
			x /= 10;
		}
	}
	return ans;
}

int main(void) {
	fib[0] = 1;
	fib[1] = 1;
	
	for (int i = 2; i <= FIB_MOD; i++) {
		fib[i] = (fib[i - 1] + fib[i - 2]) % DIG_MOD;
		fib[i] = (fib[i] + DIG_MOD) % DIG_MOD;
		fib[i] %= DIG_MOD;
	}
	
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%s", S);

		int N = strlen(S);
		Int d = 0LL;
		
		for (int i = 0; i < N; i++) {
			d = (d * 10 + (S[i] - '0')) % FIB_MOD;			
			d = (d + FIB_MOD) % FIB_MOD;
		}

		d -= 1;
		d = (d + FIB_MOD) % FIB_MOD;
		
		Int ans = fib[d];

		for (int i = 0; i < 3 - len(ans); i++) {
			printf("0");
		}
		printf("%d\n", ans);
	}
    return 0;
}
