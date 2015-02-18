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

const int MAXN = 1010;

int A, B, L, C;
int M[MAXN][MAXN];

bool vis[MAXN][MAXN];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main(void) {
	cin >> L >> C >> A >> B;

	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> M[i][j];
		}
	}

	memset(vis, false, sizeof(vis));

	for ( ; ; ) {	   
		bool ok = true;

		vis[A][B] = true;

		for (int i = 0; ok && i < 4; i++) {
			int ii = dx[i] + A;
			int jj = dy[i] + B;

			if (ii >= 1 && ii <= L && jj >= 1 && jj <= C) {
				if (M[ii][jj] == 1 && !vis[ii][jj]) {
					ok = false;
					A = ii;
					B = jj;
					break;
				}
			}
		}
		if (ok) break;
	}

	cout << A << " " << B << "\n";

	
    return 0;
}
