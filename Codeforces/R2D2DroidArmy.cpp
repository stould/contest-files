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

const int MAXN = 100005;
const int MAXM = 6;

int N, M, K;
int D[MAXN][MAXM];

struct data {
	int total;
	int cnt[MAXM];

	data() {
		total = 0;
		memset(cnt, 0, sizeof(cnt));
	}

	data(int pos) {
		total = 0;
		
		for (int i = 0; i < MAXM; i++) {
			cnt[i] = D[pos][i];
			total += cnt[i];
		}
	}
};

data tree[4 * MAXN];

data combine(data& a, data& b) {
	data ans;

	for (int i = 0; i < MAXM; i++) {
		ans.cnt[i] = max(a.cnt[i], b.cnt[i]);
		ans.total += ans.cnt[i];
	}
	
	return ans;
}

void build(int node, int l, int r) {
	if (l == r) {
		data dt;
		tree[node] = data(l);
	} else {
		int m = (l + r) / 2;

		build(2 * node, l, m);
		build(2 * node + 1, m + 1, r);

		tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
	}
}

data query(int node, int l, int r, int bl, int br) {
	if (l > r || l > br || r < bl) {
		return data();
	} else if (l >= bl && r <= br) {
		return tree[node];
	} else {
		int m = (l + r) / 2;

		data a = query(2 * node, l, m, bl, br);
		data b = query(2 * node + 1, m + 1, r, bl, br);

		return combine(a, b);
	}
}
		

int main(void) {
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> D[i][j]; 
		}
	}

	build(1, 0, N - 1);

	int best = 0;
	data ans;
	
	int l = 0, h = N - 1, m;

	
	for ( ; l <= h; ) {
		m = (l + h) / 2;

		bool found = false;
		data fd;
		
		for (int i = 0; !found && i < N - m; i++) {		
			data q = query(1, 0, N - 1, i, m + i);

			
			if (q.total <= K) {
				fd = q;
				found = true;
			}
		}

		if (found) {
			l = m + 1;
			
			if (m >= best) {
				best = m;
				ans = fd;
			}
		} else {
			h = m - 1;
		}
	}

	for (int i = 0; i < M; i++) {
		cout << ans.cnt[i] << " ";
	}
	cout << "\n";
	
    return 0;
}
