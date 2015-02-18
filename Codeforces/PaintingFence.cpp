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

const int MAXN = 5050; 
const Int INF = 10101010010101010LL;

int N;
Int P[MAXN], tree[4 * MAXN];
Int dp[MAXN][MAXN];

void build(int node, int l, int r) {
	if (l > r) {
		return;
	} else if (l == r) {
		tree[node] = P[l];
	} else {
		int m = (l + r) / 2;
		build(2 * node, l, m);
		build(2 * node + 1, m + 1, r);
		tree[node] = min(tree[2 * node], tree[2 * node + 1]);
	}	
}

Int rmq(int node, int l, int r, int bound_l, int bound_r) {
	if (l > r || bound_l > r || bound_r < l) {
		return INF;
	} else if (bound_l <= l && bound_r >= r) {
		return tree[node];
	} else {
		int m = (l + r) / 2;
		return min(rmq(2 * node, l, m, bound_l, bound_r), rmq(2 * node + 1, m + 1, r, bound_l, bound_r));
	}
}

Int func(int i, int j, int h) {
	if (i == j) {
		return 1LL;
	} else {
		Int& ans = dp[i][j];

		if (ans == -1LL) {
			Int low = rmq(1, 0, N - 1, i, j);
			int l = i;
			ans = low - h;

			for (int id = i; id <= j; id++) {
				int k = id;
				while (k <= j && P[k] > low) {
					k++;
				}
				if (k != id) {
					if (P[k] <= low) k--;
					ans += func(id, max(id, k), low);					
				}
				id = k;
			}
			chmin(ans, (Int) j - i + 1);			   
		}

		return ans;
	}
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	build(1, 0, N - 1);
	memset(dp, -1, sizeof(dp));
	cout << func(0, N - 1, 0) << "\n";

    return 0;
}
