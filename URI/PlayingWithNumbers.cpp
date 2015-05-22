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

const int MAXV = 10000001;
const int MAXN = 1002;
int N, M, K;
char C;
int P[MAXN][MAXN];
bool p_buff[MAXV];
int dp[MAXN][MAXN][6];

int a, b;
int dx[4] = {-1, 0, 1,  0};
int dy[4] = {0,  1, 0, -1};

int func(int x, int y, int us) {
	int& ans = dp[x][y][us];
	
	if (ans == -1) {
		ans = 0;
		
		for (int i = a; i < b; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (us > 0 && !p_buff[P[x][y]]) {
					chmax(ans, 1 + func(nx, ny, us - 1));
				}
				
				if (P[nx][ny] < P[x][y]) {
					chmax(ans, 1 + func(nx, ny, us));
					}					
			}
		}
	}
	
	return ans;
}

int main(void) {
	p_buff[0] = p_buff[1] = true;
	for (int i = 2; i < MAXV; i++) {
		if (!p_buff[i]) {
			for (Int j = i * (Int) i; j < MAXV; j += i) {
				p_buff[j] = true;
			}
		}
	}
	for ( ; scanf("%d%d%d", &N, &M, &K) && (N + M + K != 0); ) {
		scanf(" %c", &C);

		if (C == 'N') {
			a = 0;
			b = 2;
		} else {
			a = 2;
			b = 4;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &P[i][j]);
			}			
		}
		memset(dp, -1, sizeof(dp));

		int ans = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				chmax(ans, 1 + func(i, j, K));
			}
		}
		
		printf("%d\n", ans);
	}
    return 0;
}
