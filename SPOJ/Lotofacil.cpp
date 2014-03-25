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

const int MAXN = 30;

inline void read(int &x) {
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

int N;
int S[MAXN], P[MAXN];
int C[MAXN][MAXN];

void build(void) {
	for (int i = 0; i <= 25; i++) {
		C[i][0] = C[0][i] = 1;
	}
	for (int i = 1; i <= 25; i++) {
		for (int j = 1; j <= 25; j++) {
			if (i == j) {
				C[i][j] = 1;
			} else {
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			}
		}
	}
}

int main(void) {
	build();
	int test = 1, curr;

	for (int i = 0; i < 15; i++) {
		int c; read(c);
		S[c] += 1;
	}

	for ( ; scanf("%d", &N) == 1; ) {
		int pr = 0, ans = 0;

		for (int i = 0; i < N; i++) {
			read(P[i]);
			
			if (S[P[i]]) {
				pr += 1;
			}
		}

		printf("Aposta %d\n", test++);
		
		if (pr < 11) {
			puts("nenhum premio aqui");
		} else {
			for (int i = 11; i <= 15; i++) {
				if (pr < i || i + (N - pr) < 15) {
					 continue;
				 }
					
				int ans = C[pr][i] * C[N - pr][15 - i];

				printf("%d: %d\n", i, ans);
			}
		}
		puts("");
	}
    return 0;
}
