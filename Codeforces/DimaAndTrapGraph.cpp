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

const int MAXN = 1003;

int N;
int M;

int l[MAXN][MAXN];
int r[MAXN][MAXN];
int df[MAXN][MAXN][2];
bool ok[MAXN][MAXN];

int main(void) {
	N = in();
	M = in();

	int i;
	int j;
	int k;

	for (i = 0; i <= N; i++) {
		for (j = 0; j <= N; j++) {
			ok[i][j] = false;
			l[i][j] = 10000000;
			r[i][j] = 0;

			df[i][j][0] = 0;
			df[i][j][1] = 1000000;
		}
	}

	for (i = 0; i < M; i++) {
		int f, t, ll, rr;
		scanf("%d%d%d%d", &f, &t, &ll, &rr);

		ok[f][t] = ok[t][f] = true;

		l[f][t] = min(l[f][t], ll);
		r[t][f] = max(r[t][f], rr);
	}

	for (k = 1; k <= N; k++) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) if (i != j) {
				if (ok[i][k] && ok[k][j]) {
					df[i][j][0] = max(df[i][j][0], min(l[i][k], l[k][j]));
					df[i][j][1] = min(df[i][j][1], min(r[i][k], l[k][j]));

					printf("%d %d %d - %d %d\n", i, k, j, df[i][j][0], df[i][j][1]);
				}
			}
		}
	}

	int diff = df[1][N][1] - df[1][N][0] + 1;
	
	if (diff > 0) {
		printf("%d\n", diff);
	} else {
		printf("Nice work, Dima!\n");
	}
    return 0;
}
