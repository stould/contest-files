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

int T, N;
int P[MAXN], pr[MAXN];

int main(void) {
	rd(T);

	for (int t = 1; t <= T; t++) {
		rd(N);
		int pv = 1, ans = 0;
		unordered_map<int, int> pos;

		for (int i = 1; i <= N; i++) {
			rd(P[i]);
			pr[i] = pos[P[i]];
			pos[P[i]] = i;
		}

		for (int i = 1; i <= N; i++) {
			if (pr[i] != 0) {
				chmax(pv, pr[i] + 1);
			}
			chmax(ans, i - pv + 1);
		}
		printf("%d\n", ans);
	}
    return 0;
}
