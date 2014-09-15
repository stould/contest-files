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
const Int INF = 100000101010100LL;

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


int N, M;
int P[MAXN];

int main(void) {
	rd(N);
	rd(M);

	int l = 1, h, m;
	int ans = -1;
   
	for (int i = 0; i < N; i++) {
		rd(P[i]);
		chmax(h, P[i]);
	}

	for ( ; l <= h; ) {
		m = (l + h) / 2;
		Int sum = 0LL;
		
		for (int i = 0; i < N; i++) {
			sum += max(0LL, (Int) (P[i] - m));
		}
		
		if (sum < (Int) M) {
			h = m - 1;
		} else {
			chmax(ans, m);
			l = m + 1;
		}
	}

	printf("%d\n", ans);

    return 0;
}
