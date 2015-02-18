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

int N, M;
char pat[5][5];
int ans, ans_cnt, mask, vs;
int ok = 0;
int valid[10];
int dx[9] = {0,  0, 0, -1, 1,  1, -1, -1,  1};
int dy[9] = {0, -1, 1,  0, 0,  1, -1,  1, -1};

int p(int x, int y) {
	return x * M + y;
}

void func(int r, int c, int used) {	
	int cnt = __builtin_popcount(mask);
	if (cnt == N * M) {
		int u = __builtin_popcount(used);
		if (u < ans_cnt) {
			ans_cnt = u;
			ans = used;
		}
		return;
	}
	if (r == N && c == 0) {
		return;
	} else {
		for (int i = 0; i < r - 1; i++) {
			for (int j = 0; j < M; j++) {
				if (!(mask & (1 << p(i, j)))) {
					return;
				}
			}
		}
		int nr = r, nc = c + 1;
		if (nc == M) {
			nc = 0;
			nr = r + 1;
		}
		int new_mask = mask;
		for (int i = 0; i < vs; i++) {
			int rx = r + dx[valid[i]];
			int ry = c + dy[valid[i]];

			if (rx >= 0 && ry >= 0 && rx < N && ry < M) {
				int pos = p(rx, ry);					
				new_mask ^= (1 << pos);
			}
		}
		int old = mask;
		mask = new_mask;
		func(nr, nc, used | (1 << p(r, c)));
		mask = old;
		func(nr, nc,  used);
	}
}

int main(void) {
	int t = 1;
	for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
		printf("Case #%d\n", t++);
		for (int i = 0; i < 3; i++) {
			scanf("%s", pat[i]);
		}
		vs = 0;
		for (int i = 0; i < 9; i++) {
			int rx = 1 + dx[i];
			int ry = 1 + dy[i];
			if (pat[rx][ry] == '*') valid[vs++] = i;
		}
		ans = -1;
		ans_cnt = 1000;
		func(0, 0, 0);
		if (ans == -1) {
			printf("Impossible.\n");
		} else {
			for (int i = 0; i < N * M; i++) {
				if (ans & (1 << i)) {
					printf("%d ", i + 1);
				}
			}
			printf("\n");
		}
	}
    return 0;
}
