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

const int MAXN = 11;

int T, N;
string S[MAXN];
int xi, xj, yi, yj, zi, zj;
int dist[11][11][11][11][11][11];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

struct state {
	int ai, aj, bi, bj, ci, cj;
	state(){}
	state(int _ai, int _aj, int _bi, int _bj, int _ci, int _cj) {
		ai = _ai;
		aj = _aj;
		bi = _bi;
		bj = _bj;
		ci = _ci;
		cj = _cj;
	}
};

bool end(int ai, int aj, int bi, int bj, int ci, int cj) {
	if (ai == xi && aj == xj && bi == yi && bj == yj && ci == zi && cj == zj) {
		return true;
	} else if (ai == xi && aj == xj && bi == zi && bj == zj && ci == yi && cj == yj) {
		return true;
	} else if (ai == yi && aj == yj && bi == zi && bj == zj && ci == xi && cj == xj) {
		return true;
	} else if (ai == yi && aj == yj && bi == xi && bj == xj && ci == zi && cj == zj) {
		return true;
	} else if (ai == zi && aj == zj && bi == xi && bj == xj && ci == yi && cj == yj) {
		return true;
	} else if (ai == zi && aj == zj && bi == yi && bj == yj && ci == xi && cj == xj) {
		return true;
	}
	return false;
}

int bfs(int ai, int aj, int bi, int bj, int ci, int cj) {
	queue<state> q;
	q.push(state(ai, aj, bi, bj, ci, cj));
	
	memset(dist, 63, sizeof(dist));
	
	dist[ai][aj][bi][bj][ci][cj] = 0;

	for ( ; !q.empty(); ) {
		state curr = q.front();
		q.pop();

		/*		printf("%d %d - %d %d - %d %d\n", curr.ai, curr.aj, curr.bi, curr.bj, curr.ci, curr.cj);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == curr.ai && j == curr.aj) {
					printf("%c", 'A');
				} else if (i == curr.bi && j == curr.bj) {
					printf("%c", 'B');				
				} else if (i == curr.ci && j == curr.cj) {
					printf("%c", 'C');
				} else {
					printf("%c", S[i][j]);
				}
			}
			printf("\n");
		}
		printf("\n");
		*/
		if (end(curr.ai, curr.aj, curr.bi, curr.bj, curr.ci, curr.cj)) {
			return dist[curr.ai][curr.aj][curr.bi][curr.bj][curr.ci][curr.cj];
		}
		
		for (int i = 0; i < 4; i++) {
			int aii = curr.ai + dx[i];
			int ajj = curr.aj + dy[i];
			int bii = curr.bi + dx[i];
			int bjj = curr.bj + dy[i];
			int cii = curr.ci + dx[i];
			int cjj = curr.cj + dy[i];
			
			if (aii >= 0 && aii < N && ajj >= 0 && ajj < N) {
				if (S[aii][ajj] == '#') {
					aii = curr.ai;
					ajj = curr.aj;
				}
			} else {
				aii = curr.ai;
				ajj = curr.aj;
			}

			if (bii >= 0 && bii < N && bjj >= 0 && bjj < N) {
				if (S[bii][bjj] == '#') {
					bii = curr.bi;
					bjj = curr.bj;
				}
			} else {
				bii = curr.bi;
				bjj = curr.bj;
			}

			if (cii >= 0 && cii < N && cjj >= 0 && cjj < N) {
				if (S[cii][cjj] == '#') {
					cii = curr.ci;
					cjj = curr.cj;
				}
			} else {
				cii = curr.ci;
				cjj = curr.cj;
			}

			if (aii == bii && ajj == bjj) {
				aii = curr.ai;
				ajj = curr.aj;
				bii = curr.bi;
				bjj = curr.bj;
			}
			if (aii == cii && ajj == cjj) {
				aii = curr.ai;
				ajj = curr.aj;
				cii = curr.ci;
				cjj = curr.cj;
			}
			if (bii == cii && bjj == cjj) {
				bii = curr.bi;
				bjj = curr.bj;
				cii = curr.ci;
				cjj = curr.cj;
			}
			if (aii == cii && ajj == cjj) {
				aii = curr.ai;
				ajj = curr.aj;
				cii = curr.ci;
				cjj = curr.cj;
			}			

			if (dist[aii][ajj][bii][bjj][cii][cjj] > dist[curr.ai][curr.aj][curr.bi][curr.bj][curr.ci][curr.cj] + 1) {
				dist[aii][ajj][bii][bjj][cii][cjj] = dist[curr.ai][curr.aj][curr.bi][curr.bj][curr.ci][curr.cj] + 1;
				q.push(state(aii, ajj, bii, bjj, cii, cjj));
			}
		}
	}
	return -1;
}

int main(void) {
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		cin >> N;

		int ai = -1, aj = -1;
		int bi = -1, bj = -1;
		int ci = -1, cj = -1;

		xi = yi = zi = -1;

		for (int i = 0; i < N; i++) {
			cin >> S[i];
			
			for (int j = 0; j < N; j++) {
				if (S[i][j] == 'A' || S[i][j] == 'B' || S[i][j] == 'C') {
					if (ai == -1) {
						ai = i;
						aj = j; 
					} else if (bi == -1) {
						bi = i;
						bj = j; 
					} else {	
						ci = i;
						cj = j; 
					}
					S[i][j] = '.';
				} else if (S[i][j] == 'X') {
					if (xi == -1) {
						xi = i;
						xj = j;
					} else if (yi == -1) {
						yi = i;
						yj = j;
					} else {
						zi = i;
						zj = j;
					}
				}
			}
		}		
		int ans = bfs(ai, aj, bi, bj, ci, cj);

		printf("Case %d: ", t);

		if (ans == -1) {
			printf("trapped\n");
		} else {
			printf("%d\n", ans);
		}
		
	}
    return 0;
}
