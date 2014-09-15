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

const int MAXN = 502;
const int INF = INT_MAX / 3;

int N, M, Q;
int P[MAXN][MAXN];

pair<int, int> tree[4 * MAXN][4 * MAXN];

void build_y(int nx, int ny, int xl, int xr, int yl, int yr) {
	if (yl == yr) {
		if (xl == xr) {
			tree[nx][ny].first = tree[nx][ny].second = P[xl][yl];
		} else {
			tree[nx][ny].first = min(tree[2 * nx][ny].first, tree[2 * nx + 1][ny].first);
			tree[nx][ny].second = max(tree[2 * nx][ny].second, tree[2 * nx + 1][ny].second);
		}
	} else {
		int m = (yl + yr) / 2;

		build_y(nx, 2 * ny, xl, xr, yl, m);
		build_y(nx, 2 * ny + 1, xl, xr, m + 1, yr);
		
		tree[nx][ny].first = min(tree[nx][2 * ny].first, tree[nx][2 * ny + 1].first);
		tree[nx][ny].second = max(tree[nx][2 * ny].second, tree[nx][2 * ny + 1].second);
	}
}

void build_x(int nx, int xl, int xr) {
	if (xl > xr) {
		return;
	} else if (xl != xr) {
		int m = (xl + xr) / 2;
		
		build_x(2 * nx, xl, m);
		build_x(2 * nx + 1, m + 1, xr);
	}
	build_y(nx, 1, xl, xr, 0, M - 1);
}

pair<int, int> query_y(int nx, int ny, int xl, int xr, int yl, int yr, int bound_lx, int bound_rx, int bound_ly, int bound_ry) {
	if (yl > yr || yl > bound_ry || yr < bound_ly) {
		return make_pair(INF, -INF);
	} else if (yl >= bound_ly && yr <= bound_ry) {
		return tree[nx][ny];
	} else {
		int m = (yl + yr) / 2;

		pair<int, int> q1 = query_y(nx, 2 * ny, xl, xr, yl, m, bound_lx, bound_rx, bound_ly, bound_ry);
		pair<int, int> q2 = query_y(nx, 2 * ny + 1, xl, xr, m + 1, yr, bound_lx, bound_rx, bound_ly, bound_ry);

		return make_pair(min(q1.first, q2.first), max(q1.second, q2.second));
	}
}

pair<int, int> query_x(int nx, int ny, int xl, int xr, int yl, int yr, int bound_lx, int bound_rx, int bound_ly, int bound_ry) {
	if (xl > xr || xl > bound_rx || xr < bound_lx) {
		return make_pair(INF, -INF);
	} else if (xl >= bound_lx && xr <= bound_rx) {
		return query_y(nx, 1, xl, xr, 0, M - 1, bound_lx, bound_rx, bound_ly, bound_ry);
	} else {
		int m = (xl + xr) / 2;
		
		pair<int, int> q1 = query_x(2 * nx, ny, xl, m, yl, yr, bound_lx, bound_rx, bound_ly, bound_ry);
		pair<int, int> q2 = query_x(2 * nx + 1, ny, m + 1, xr, yl, yr, bound_lx, bound_rx, bound_ly, bound_ry);

		return make_pair(min(q1.first, q2.first), max(q1.second, q2.second));
	}
}

pair<int, int> query(int nx, int ny, int xl, int xr, int yl, int yr, int bound_lx, int bound_rx, int bound_ly, int bound_ry) {
	return query_x(1, 1, xl, xr, yl, yr, bound_lx, bound_rx, bound_ly, bound_ry);
}

void update_y(int nx, int ny, int xl, int xr, int yl, int yr, int posx, int posy, int value) {
	if (yl == yr) {
		if (xl == xr) {
			tree[nx][ny].first = tree[nx][ny].second = value;
		} else {
			tree[nx][ny].first = min(tree[2 * nx][ny].first, tree[2 * nx + 1][ny].first);
			tree[nx][ny].second = max(tree[2 * nx][ny].second, tree[2 * nx + 1][ny].second);
		}
	} else {
		int m = (yl + yr) / 2;
		
		if (posy <= m) {
			update_y(nx, 2 * ny, xl, xr, yl, m, posx, posy, value);
		} else {
			update_y(nx, 2 * ny + 1, xl, xr, m + 1, yr, posx, posy, value);
		}

		tree[nx][ny].first = min(tree[nx][2 * ny].first, tree[nx][2 * ny + 1].first);
		tree[nx][ny].second = max(tree[nx][2 * ny].second, tree[nx][2 * ny + 1].second);
	}
}

void update_x(int nx, int ny, int xl, int xr, int yl, int yr, int posx, int posy, int value) {	
	if (xl != xr) {
		int m = (xl + xr) / 2;

		if (posx <= m) {
			update_x(2 * nx, ny, xl, m, yl, yr, posx, posy, value);
		} else {
			update_x(2 * nx + 1, ny, m + 1, xr, yl, yr, posx, posy, value);
		}
	}
	update_y(nx, 1, xl, xr, 0, M - 1, posx, posy, value);
}

void update(int nx, int ny, int xl, int xr, int yl, int yr, int posx, int posy, int value) {
	return update_x(1, 1, xl, xr, yl, yr, posx, posy, value);
}


int main(void) {
	for ( ; scanf("%d%d", &N, &M) == 2 && N + Q != 0; ) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &P[i][j]);
			}
		}

		build_x(1, 0, N - 1);

		char T;
		int Ux, Uy, Lx, Ly, V;

		scanf("%d", &Q);
		
		for (int i = 0; i < Q; i++) {
			scanf(" %c", &T);
			if (T == 'q') {
				scanf("%d%d%d%d", &Ux, &Uy, &Lx, &Ly);
				Ux -= 1;
				Uy -= 1;
				Lx -= 1;
				Ly -= 1;
				pair<int, int> q = query(1, 1, 0, N - 1, 0, M - 1, Ux, Lx, Uy, Ly);
				printf("%d %d\n", q.second, q.first);
			} else {
				scanf("%d%d%d", &Ux, &Uy, &V);
				Ux -= 1;
				Uy -= 1;
				update(1, 1, 0, N - 1, 0, M - 1, Ux, Uy, V);
			}
		}
	}
    return 0;
}
