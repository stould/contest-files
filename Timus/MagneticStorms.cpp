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

const int MAXN = 25005;

int N, M;
int P[MAXN];
int tree[4 * MAXN];

void build(int node, int l, int r) {
	if (l == r) {
		tree[node] = P[l];
	} else {
		int m = (l + r) / 2;

		build(2 * node, l, m);
		build(2 * node + 1, m + 1, r);

		tree[node] = max(tree[2 * node], tree[2 * node + 1]);
	}
}

int query(int node, int l, int r, int bl, int br) {
	if (l > r || l > br || r < bl) {
		return INT_MIN;
	} else if (l >= bl && r <= br) {
		return tree[node];
	} else {
		int m = (l + r) / 2;
			
		int a = query(2 * node, l, m, bl, br);
		int b = query(2 * node + 1, m + 1, r, bl, br);

		return max(a, b);
	}
}



int main(void) {
	cin >> M;

	while (cin >> P[N]) {
		if (P[N] == -1) break;
		N++;		
	}

	build(1, 0, N - 1);

	for (int i = M - 1; i < N; i++) {
		cout << query(1, 0, N - 1, i - M + 1, i) << "\n";
	}
	
	return 0;
}
