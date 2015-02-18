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

inline void rd(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;
    for (; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
    if (c == '-') {
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

const int MAXN = 100005;

int N, K;
bool sot(bitset<MAXN> a, bitset<MAXN> b) {
	return a.count() > b.count();
}
int main(void) {
	for ( ; ; ) {
		rd(N);
		rd(K);
		if (N == 0 && K == 0) break;
		bitset<MAXN> s[K];	
		for (int i = 0; i < N; i++) {
			int Ni, p;
			rd(Ni);
			for (int j = 0; j < Ni; j++) {				
				rd(p);
				p--;
				s[p].set(i);
			}
		}
		bool ok = false;
		for (int i = 0; !ok && i < (1 << K); i++) {
			bool had = false;
			bitset<MAXN> bs;
			for (int j = 0; j < K; j++) {
				if (i & (1 << j)) {
					if (had) {
						if ((bs & s[j]).count() > 0) {
							bs ^= s[j];
						}
					} else {
						had = true;
						bs = s[j];
					}
				}
			}
			if (bs.count() == N) {
				ok = true;
				break;
			}
		}
		puts(ok ? "S" : "N");
	}
    return 0;
}
