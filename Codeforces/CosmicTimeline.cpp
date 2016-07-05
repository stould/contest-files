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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned uint;

const int MAXN = 100005;

int N;
int D[MAXN], V[MAXN], T[MAXN];
int sorted[MAXN], sorted_id[MAXN], sorted_rv[MAXN];
Int dp[MAXN];
Int tree[4 * MAXN];

Int query(int node, int l, int r, int bl, int br) {
	if (l > r || l > br || r < bl) {
		return -1;
	} else if (l >= bl && r <= br) {
		return tree[node];
	} else {
		int m = (l + r) / 2;
		
		int a = query(2 * node, l, m, bl, br);
		int b = query(2 * node + 1, m + 1, r, bl, br);

		return max(a, b);
	}
}

void update(int node, int l, int r, int pos, Int value) {
	if (l > r) {
		return;
	} else if (l == r) {
		tree[node] = value;
	} else {
		int m = (l + r) / 2;

		if (pos <= m) {
			update(2 * node, l, m, pos, value);
		} else {
			update(2 * node + 1, m + 1, r, pos, value);
		}

		tree[node] = max(tree[2 * node], tree[2 * node + 1]);
	}
}

bool cmp(int a, int b) {
	return D[a] < D[b];
}

int bs_leftmost(int v) {
	int l = 0, h = N - 1, m;
	int best = INT_MAX;
	
	while (l <= h) {
		m = (l + h) / 2;

		if (D[sorted_id[m]] < v) {
			l = m + 1;
		} else {
			best = min(best, m);
			h = m - 1;
		}
	}

	if (best == INT_MAX) best = -1;
	
	return best;
}


int bs_rightmost(int v) {
	int l = 0, h = N - 1, m;
	int best = -1;
	
	while (l <= h) {
		m = (l + h) / 2;

		if (D[sorted_id[m]] > v) {
			h = m - 1;		
		} else {
			l = m + 1;
			best = max(best, m);
		}
	}
	
	return best;
}

int main(void) {
	cin >> N;

	Int ans = 0;

	for (int i = 0; i < N; i++) {
		cin >> D[i] >> V[i] >> T[i];
		sorted[i] = i;
	}

	sort(sorted, sorted + N, cmp);

	for (int i = 0; i < N; i++) {
		sorted_id[i] = sorted[i];
		sorted_rv[sorted[i]] = i;
	}	
	for (int i = 0; i < N; i++) {
		int l = bs_leftmost(D[i] - T[i]);
		int r = bs_rightmost(D[i]);
		
		dp[i] = V[i];

		if (l != -1 && r != -1) {		
			chmax(dp[i], query(1, 0, N - 1, l, r) + V[i]);		
			update(1, 0, N - 1, sorted_rv[i], dp[i]);
		}
		chmax(ans, dp[i]);
	}

	cout << ans << "\n";
	
	return 0;
}
