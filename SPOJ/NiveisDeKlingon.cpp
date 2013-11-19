#include <bits/stdc++.h>
using namespace std;

typedef long long int Int;

const int inf = 0x3f3f3f3f;
const Int hugeinf = 0x3f3f3f3f3f3f3f3fll;
const double eps = 1e-9;

const int MAXN = 10005;

int N, M;

int K[MAXN];
int A[MAXN];

inline void fastRead_int(int &x) {
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

int main(void) {
	int i, j;

	for ( ; ; ) {
	    fastRead_int(N);

	    if (N == 0) break;

		for (i = 0; i <= 1000; i++) A[i] = 0;

        int x;

        int ans = INT_MAX / 3;

		for (i = 0; i < N; i++) {
		    fastRead_int(M);

            for (j = 0; j <= 1000; j++) K[j] = 0;

			for (j = 0; j < M; j++) {
                fastRead_int(x);
				K[x] += 1;
			}

			for (j = 1; j <= 1000; j++) {
			    K[j] += K[j - 1];
		        A[j] += abs(K[j] - (M - K[j]));

		        if (i == N - 1) ans = min(ans, A[j]);
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}

