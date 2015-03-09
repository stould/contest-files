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

int T, N;
int P[10], C[10];
int dp[10][(1 << 10)];

inline void fio(int &x) {
    register int c = getchar_unlocked();

    x = 0;

    int neg = 0;

    for (; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if (c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }

    for ( ; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }

    if (neg) {
        x = -x;
    }
}


int func(int pos, int mask) {
	if (pos == N) return 0;
	
	int& ans = dp[pos][mask];
	
	if (ans == -1) {
		ans = INT_MAX;
		
		for (int i = 0; i < N; i++) {
			if (!(mask & (1 << i))) {
				chmin(ans, max(lcm(P[pos], C[i]), func(pos + 1, mask | (1 << i))));
			}
		}
	}
	
	return ans;
}

int main(void) {
	fio(T);

	for (int t = 1; t <= T; t++) {
		fio(N);
		
		for (int i = 0; i < N; i++) {
			fio(P[i]);
		}
		for (int i = 0; i < N; i++) {
			fio(C[i]);
		}

		memset(dp, -1, sizeof(dp));
		
		int ans = func(0, 0);
		
		printf("Caso #%d: %d\n", t, ans);
	}
	
    return 0;
}
