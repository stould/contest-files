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

int L, N, M;
int dst[35][35][35];
char C[35][35][35];
int dl[6] = { 0, 0,  0, 0, -1, 1};
int dx[6] = {-1, 1,  0, 0,  0, 0};
int dy[6] = { 0, 0, -1, 1,  0, 0};	

int main(void) {
	for ( ; scanf("%d%d%d", &L, &N, &M); ) {
		if (L + N + M == 0) break;

		int bl = -1, bi, bj;
		int el = -1, ei, ej;
		
		for (int a = 0; a < L; a++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					scanf(" %c", &C[a][i][j]);

					if (C[a][i][j] == 'S') {
						bl = a;
						bi = i;
						bj = j;
					} else if (C[a][i][j] == 'E') {
						el = a;
						ei = i;
						ej = j;							
					}
				}
			}
		}
		
		assert(bl != -1 && el != -1);

		queue<pair<int, pair<int, int> > > q;
		q.push(make_pair(bl, make_pair(bi, bj)));

		memset(dst, 63, sizeof(dst));
		dst[bl][bi][bj] = 0;
		
		for ( ; !q.empty(); ) {
			int cl = q.front().first;
			int ci = q.front().second.first;
			int cj = q.front().second.second;
			q.pop();

			for (int i = 0; i < 6; i++) {
				int nl = cl + dl[i];
				int ni = ci + dx[i];
				int nj = cj + dy[i];

				if (ni >= 0 && nj >= 0 && nl >= 0 && ni < N && nj < M && nl < L) {
					if (C[nl][ni][nj] != '#') {
						if (dst[nl][ni][nj] > dst[cl][ci][cj] + 1) {
							dst[nl][ni][nj] = dst[cl][ci][cj] + 1;
							q.push(make_pair(nl, make_pair(ni, nj)));
						}
					}
				}
			}			
		}

		int ans = dst[el][ei][ej];

		if (ans == 1061109567) {
			printf("Trapped!\n");
		} else {
			printf("Escaped in %d minute(s).\n", ans);
		}
	}
    return 0;
}
