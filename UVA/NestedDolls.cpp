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
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 20020;
const int MAX_TREE = 10010;
const int INF = INT_MAX / 5;

int T, N;
pair<int, int> P[MAXN];
//len, id - min_len
pair<int, int> tree[4 * MAX_TREE];
int dp[MAXN];

void build(int id, int l, int r) {
	if (l > r) return;
	if (l == r) {
		tree[id] = make_pair(l, 0);
	} else {
		int m = (l + r) / 2;

		build(2 * id, l, m);
		build(2 * id + 1, m + 1, r);

		tree[id] = min(tree[2 * id], tree[2 * id + 1]);
	}
}

pair<int, int> query(int id, int l, int r, int bl, int br) {
	if (l > r || l > br || r < bl) {
		return make_pair(-INF, 0);
	} else if (l >= bl && r <= br) {
		return tree[id];
	} else {
		int m = (l + r) / 2;
		
		pair<int, int> a = query(2 * id, l, m, bl, br);
		pair<int, int> b = query(2 * id + 1, m + 1, r, bl, br);
		
		pair<int, int> ans = make_pair(-INF, 0);

		if (a.second > 0) ans = max(ans, a);
		if (b.second > 0) ans = max(ans, b);
		
		return ans;
	}
}

void update(int id, int l, int r, int pos, int val) {
	if (l > r) {
		return;
	} else if (l == r) {
		tree[id] = make_pair(pos, val);
	} else {
		int m = (l + r) / 2;
		
		if (pos <= m) {
			update(2 * id, l, m, pos, val);
		} else {
			update(2 * id + 1, m + 1, r, pos, val);
		}

		tree[id] = make_pair(pos, 0);
		
		if (tree[2 * id].second > 0) {
			if (tree[id].second == 0 || (tree[id].second > 0 && tree[id].first < tree[2 * id].first)) {
				tree[id] = tree[2 * id];
			}
			//cout << id << " " << pos << " " << tree[id].second << "\n";
		}
		if (tree[2 * id + 1].second > 0) {
			if (tree[id].second == 0 || (tree[id].second > 0 && tree[id].first < tree[2 * id + 1].first)) {
				tree[id] = tree[2 * id + 1];				
			}
			//cout << id << " " << pos << " " << tree[id].second << "\n";
		}
		//cout << id << " " << tree[id].first << " " << tree[id].second << "\n";
	}
}

int main(void) {
	cin >> T;

	while (T--) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> P[i].first >> P[i].second;
		}

		build(1, 0, MAX_TREE - 1);
		
		sort(P, P + N);

		dp[0] = N;

		update(1, 0, MAX_TREE - 1, P[0].second, 1);

		for (int i = 1; i < N; i++) {
			dp[i] = dp[i - 1];

			int beg = -1;

			int l = 0, h = i - 1, m;

			while (l <= h) {
				m = (l + h) / 2;

				if (P[m].first < P[i].first) {
					beg = m;
					l = m + 1;
				} else {
					h = m - 1;
				}
			}
			
			if (beg >= 0) {				
				pair<int, int> q = query(1, 0, MAX_TREE - 1, 1, P[i].second - 1);
				
				cout << i << " " << beg << " " << P[i].second << " " << q.first << " " << q.second << "\n";
				
				if (q.second > 0) {
					dp[i] -= 1;
					
					update(1, 0, MAX_TREE - 1, q.first, q.second - 1);
				}
			}
			//cout << dp[i] << "\n";
			update(1, 0, MAX_TREE - 1, P[i].second, query(1, 0, MAX_TREE - 1, P[i].second, P[i].second).second + 1);
		}

		cout << dp[N - 1] << "\n";
	}
	return 0;
}
