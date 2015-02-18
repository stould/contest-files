#include <bits/stdc++.h>

using namespace std;

const int INF = 1000050000;
const int MAXN = 1000005;

int N, C, X;
int qual[MAXN];
pair<int, int> P[MAXN];
int tree[4 * MAXN];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	} else {
		return a.first < b.first;
	}
}

int checkQ(int X) {
	int l = 0, h = N - 1, m;
	int ans = INT_MAX;

	for ( ; l <= h; ) {
		m = (l + h) / 2;

		if (P[m].second > X) {
			h = m - 1;     
		} else {
			ans = min(ans, m); 
			l = m + 1;
		}
	}
	if (ans == INT_MAX) ans = -1;
	return ans;
}


void build(int node, int l, int r) {
	if (l == r) {
		tree[node] = P[l].first;
	} else {
		int m = (l + r) / 2;

		build(2 * node, l, m);
		build(2 * node + 1, m + 1, r);

		tree[node] = min(tree[2 * node], tree[2 * node + 1]);
	}
}

int query(int node, int l, int r, int bound_l, int bound_r) {
	if (l > r || l > bound_r || r < bound_l) {
		return INF;
	} else if (l >= bound_l && r <= bound_r) {
		return tree[node];
	} else {
		int m = (l + r) / 2;

		int a = query(2 * node, l, m, bound_l, bound_r);
		int b = query(2 * node + 1, m + 1, r, bound_l, bound_r);

		return min(a, b);
	}
}
int main(void) {
	for ( ; cin >> N && N != 0; ) {
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &P[i].first, &P[i].second);
		}
   
		sort(P, P + N, cmp);
   
		build(1, 0, N - 1);

		for (int i = 0; i < N; i++) {
			qual[i] = P[i].second;
		}

		scanf("%d", &C);

		for (int i = 0; i < C; i++) {
			scanf("%d", &X);

			if (qual[N - 1] < X) {
				printf("-1\n");
			} else {
				int pos = upper_bound(qual, qual + N, X - 1) - qual;
				int ans = query(1, 0, N - 1, pos, N - 1);
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
