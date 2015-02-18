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

const int INF = INT_MAX / 3;
const int MAXN = 150;


int N, M, L;
char S[MAXN][MAXN], buff[1010];
int dp[MAXN][MAXN], len[MAXN];
int sL[MAXN];

inline void rd(int &x) {
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


int func(int l, int r) {
	if (l > r) {
		return 0;
	} else {
		int& ans = dp[l][r];

		if (ans == -1) {
			ans = L;

			if (len[l] > r) {
				ans = func(l + 1, r);
			} else {
				for (int i = l; i <= len[l]; i++) {
					chmin(ans, 1 + func(l, i - 1) + func(i + 1, r));
				} 
			}
		}

		return ans;
	}
}

int main(void) {
	for ( ; ; ) {
		rd(N);
		rd(M);

		if (N == 0 && M == 0) break;

		char ch;
		for (int i = 0; i < N; i++) {
			sL[i] = 0;
			for ( ; ; ) {
				ch = getchar_unlocked();
				if (ch == '\n') break;
				S[i][sL[i]++] = ch;
			}
		}

		int ans = 0;

		for (int i = 0; i < M; i++) {
			L = 0;
			for ( ; ; ) {
				ch = getchar_unlocked();
				if (ch == '\n') break;
				buff[L++] = ch;			
			}

			memset(dp, -1, sizeof(dp));

			for (int i = 0; i < L; i++) {
				len[i] = L;
				
				for (int j = 0; j < N; j++) {
					if (i + sL[j] <= L) {
						int ed = 0;
						while (ed < sL[j] && buff[i + ed] == S[j][ed]) {
							ed += 1;
						}
						if (ed == sL[j]) {
							chmin(len[i], i + sL[j] - 1);
						}
					}
				}				
			}

			ans += func(0, L - 1);
		}
		printf("%d\n", ans);
	}
    return 0;
}
