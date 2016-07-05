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

const int MAXN = 100005;

int N, Q;
int tree[4][MAXN];

void update(int t, int i, int val) {
	for ( ; i <= N; i += (i & -i)) {
		tree[t][i] += val;
	}
}

int r_q(int t, int i) {
	int ans = 0;

	for ( ; i >= 1; i -= (i & -i)) {
		ans += tree[t][i];
	}
	
	return ans;
}

int query(int t, int l, int r) {
	return r_q(t, r) - r_q(t, l - 1);
}

int main(void) {
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	
	cin >> N >> Q;

	for (int i = 1; i <= N; i++) {
		int K;
		cin >> K;

		update(K, i, 1);
	}

	for (int i = 0; i < Q; i++) {
		int L, R;
		cin >> L >> R;

		int a = query(1, L, R);
		int b = query(2, L, R);
		int c = query(3, L, R);

		cout << a << " " << b << " " << c << "\n";
	}
	
	return 0;
}
