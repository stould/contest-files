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

const int MAXN = 300005;
const Int MOD = 1000000009LL;

int N, M, A, B, C;
int P[MAXN];

Int tree[4 * MAXN];
int ID[4 * MAXN];
Int F[MAXN];
Int lazy[4 * MAXN];


inline void rd(int &x) {
    register int c = getchar_unlocked();

    x = 0;

    int neg = 0;

    for (; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if (c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }

    for ( ; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }

    if (neg) {
        x = -x;
    }
}



void st(void) {
	F[0] = F[1] = 1LL;

	for (int i = 2; i < MAXN; i++) {
		F[i] = (F[i - 1] % MOD + F[i - 2] % MOD) % MOD;
	}
}

void build(int node, int l, int r) {
	if (l == r) {
		tree[node] = (Int) P[l];
		ID[node] = l;
	} else {
		int m = (l + r) / 2;

		build(2 * node, l, m);
		build(2 * node + 1, m + 1, r);

		tree[node] = (tree[2 * node] + tree[2 * node + 1]) % MOD;
	}
}

Int query(int node, int l, int r, int bound_l, int bound_r) {
	if (bound_l > r || bound_r < l) {
		return 0;
	} else if (bound_l <= l && bound_r >= r) {
		return tree[node];
	} else {
		int m = (l + r) / 2;

		Int q1 = query(2 * node, l, m, bound_l, bound_r) % MOD;
		Int q2 = query(2 * node + 1, m + 1, r, bound_l, bound_r) % MOD;

		return (q1 + q2) % MOD;
	}
}

void update(int node, int l, int r, int bound_l, int bound_r, int start) {
	if (bound_l > r || bound_r < l) {
		return;
	} else if (l == r) {
		
		tree[node] = (tree[node] + F[ID[node] - start]) % MOD;
	} else {
		int m = (l + r) / 2;

		update(2 * node, l, m, bound_l, bound_r, start);
		update(2 * node + 1, m + 1, r, bound_l, bound_r, start);

		tree[node] = (tree[2 * node] + tree[2 * node + 1] % MOD) % MOD;
	}
}

int main(void) {
	st();
	rd(N);
	rd(M);

	for (int i = 0; i < N; i++) {
		rd(P[i]);
	}
	
	build(1, 0, N - 1);

	for (int i = 0; i < M; i++) {
		rd(A);
		rd(B);
		rd(C);

		B--;
		C--;
		
		if (A == 1) {
			update(1, 0, N - 1, B, C, B);
		} else {
			cout << query(1, 0, N - 1, B, C) % MOD << endl;
		}
	}
    return 0;
}
