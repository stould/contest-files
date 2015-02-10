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

const int MAXN = 505;

int N, M, Q;
int P[MAXN][MAXN];

bool inside(int i, int j, int L, int R) {
	//cout << P[i][j] << " - " << L << " " << R << endl;
	return P[i][j] >= L && P[i][j] <= R;
}

bool ok(int i, int j, int m, int L, int R) {
	return inside(i, j, L, R) && inside(i, j + m, L, R) && inside(i + m, j, L, R) && inside(i + m, j + m, L, R);
}

int query(int L, int R) {
	int best = 0;
	
	for (int i = 0; i < N; i++) {		
		int j = upper_bound(P[i], P[i] + M, L - 1) - P[i];
		
		int l = 0, h = min(N - i, M - j) - 1, m;		
		int curr = -1;

		if (j >= M or h < 0) continue;

		if (ok(i, j, 0, L, R)) {
			chmax(best, 1);
		}
		
		for ( ; l <= h; ) {
			m = (l + h) / 2;

			if (ok(i, j, m, L, R)) {
				curr = m;
				l = m + 1;
			} else {
				h = m - 1;
			}
		}
		//cout << i << " " << j << " " << P[i][j] << " => " << L << " " << R << " " << " curr => " << curr << endl;
		if (curr != -1) {
			chmax(best, curr + 1);
		}
	}

	return best;
}

int main(void) {
	for ( ; scanf("%d%d", &N, &M); ) {
		if (N == 0 && M == 0) {
			break;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &P[i][j]);
			}
		}

		scanf("%d", &Q);

		for (int q = 0; q < Q; q++) {
			int L, R;
			
			scanf("%d%d", &L, &R);
			
			printf("%d\n", query(L, R));
		}

		printf("-\n");
	}
    return 0;
}
