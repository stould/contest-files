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
const int INF = INT_MAX / 3;

int N;
int P[MAXN], L[MAXN], R[MAXN];
int tree[4 * MAXN];

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

int query(int node, int l, int r, int bound_l, int bound_r) {
	if (l > r || l > bound_r || r < bound_l) {
		return INF;
	} else if (l >= bound_l && r <= bound_r) {
		return tree[node];
	} else {
		int m = (l + r) / 2;

		return min(query(2 * node, l, m, bound_l, bound_r), query(2 * node + 1, m + 1, r, bound_l, bound_r));
	}
}

void fillL(void) {
	stack<int> s;

	for (int i = 0; i < N; i++) {
		if (s.empty()) {
			L[i] = i;
		} else {
			while (!s.empty() && P[s.top()] <= P[i]) {
				s.pop();
			}
			if (!s.empty()) {
				L[i] = s.top();
			} else {
				L[i] = i;
			}
		}
		s.push(i);
	}
}

void fillR(void) {
	stack<int> s;

	for (int i = N - 1; i >= 0; i--) {
		if (s.empty()) {
			R[i] = i;
		} else {
			while (!s.empty() && P[s.top()] <= P[i]) {
				s.pop();
			}
			if (!s.empty()) {
				R[i] = s.top();
			} else {
				R[i] = i;
			}
		}
		s.push(i);
	}
}

int main(void) {
	for ( ; scanf("%d", &N) == 1; ) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
		}
		fillL();
		fillR();

		build(1, 0, N - 1);

		vector<int> ans;

		for (int i = 1; i < N - 1; i++) {
			if (P[i] > P[i - 1] && P[i] > P[i + 1]) {
				bool okL = true;
				bool okR = true;

				if (i - L[i] > 1) {
					okL = (P[i] - query(1, 0, N - 1, L[i], i - 1) >= 150000);
				}
				if (R[i] - i > 1) {
					okR = (P[i] - query(1, 0, N - 1, i + 1, R[i]) >= 150000);
				}
				if (okL && okR) {
					ans.push_back(i + 1);
				}
			}
		}

		for (int i = 0; i < (int) ans.size(); i++) {
			if (i) printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	}
    return 0;
}
