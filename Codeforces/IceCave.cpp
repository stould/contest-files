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

const int MAXN = 550;

int N, M, reach;
char C[MAXN][MAXN];
int R1, C1, R2, C2;
bool vis[MAXN][MAXN];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool inside(int i, int j) {
	return i >= 0 && j >= 0 && i < N && j < M;
}

void dfs(int i, int j) {
	if (i == R2 && j == C2) {
		reach = true;
	}

	if (vis[i][j]) return;

	vis[i][j] = true;

	for (int x = 0; x < 4; x++) {
		int di = i + dx[x];
		int dj = j + dy[x];

		if (inside(di, dj)) {
			if ((di == R2 && dj == C2) || C[di][dj] == '.') {
				dfs(di, dj);
			}
		}
	}
}

int main(void) {
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", C[i]);
	}
	
	scanf("%d%d%d%d", &R1, &C1, &R2, &C2);

	R1 -= 1; R2 -= 1;
	C1 -= 1; C2 -= 1;

	int free = 0;
	
	for (int i = 0; i < 4; i++) {
		int di = R2 + dx[i];
		int dj = C2 + dy[i];
		
		if (inside(di, dj)) {
			if (C[di][dj] == '.') {
				free += 1;
			}
		}
	}				
	
	dfs(R1, C1);

	if (reach) {
		if (R1 == R2 && C1 == C2) {
			if (free >= 1) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		} else {
			if (C[R2][C2] == 'X') {
				printf("YES\n");
			} else {
				bool ok = false;
				
				for (int i = 0; i < 4; i++) {
					int di = R2 + dx[i];
					int dj = C2 + dy[i];
					
					if (inside(di, dj)) {
						if (C[di][dj] == '.') {
							C[di][dj] = 'X';

							reach = false;							
							memset(vis, 0, sizeof(vis));

							dfs(R1, C1);

							if (reach) {
								ok = true;
							}
							C[di][dj] = '.';
						}
					}
				}				
				
				if (ok) {
					printf("YES\n");
				} else {
					printf("NO\n");
				}
			}
		}
	} else {
		printf("NO\n");	
	}
	
	return 0;
}
