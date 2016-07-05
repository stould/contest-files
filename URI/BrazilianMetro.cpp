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
int C[15][15];
int vis[15];
int outcome;

int func(int x, int y) {
	int ans = 0;
	
	C[x][y] = 1;

	int buf[15][15];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			buf[i][j] = C[i][j];
		}
	}
	
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				buf[i][j] |= (buf[i][k] && buf[k][j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!buf[i][j]) {
				ans += 1;
			}
		}
	}
	
	C[x][y] = 0;

	return ans;
}

int dfs(int x) {
	if (vis[x]) return vis[x];

	int ans = 1;

	for (int i = 0; i < N; i++) {
		if (i != x && C[x][i]) {
			ans += dfs(i);
		}
	}

	return vis[x] = ans;
}

void gen(int x, int y) {
	//cout << x << " " << y << "\n";
	if (y == N) {
		x += 1;
		y = 0;
	}
	if (x == N) {
		memset(vis, 0, sizeof(vis));
		if (dfs(x) == N) {
			outcome += 1;
		}
	} else {
		gen(x, y + 1);
		
		if (!C[x][y]) {
			C[x][y] = 1;
			gen(x, y + 1);
			C[x][y] = 0;
		}
	}
}

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		C[A][B] = C[B][A] = 1;
	}
	
	int ans_a = -1, ans_b = -1;
	int curr = 0;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (!C[i][j]) {				
				outcome = 0;
				C[i][j] = C[j][i] = 1;
				gen(0, 0);
				cout << outcome << "\n";
				if (outcome > curr) {
					curr = outcome;
					ans_a = i;
					ans_b = j;
				}
				C[i][j] = C[j][i] = 0;
			}
		}
	}
	
	cout << ans_a << " " << ans_b << "\n";
	
	return 0;
}
