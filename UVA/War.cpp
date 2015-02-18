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

const int MAXN = 20010;

int N;
int rnk[MAXN], id[MAXN];

int inv(int a) {
	return a + 10000;
}

void buildUF() {
	for (int i = 0; i < MAXN; i++) {
		id[i] = i;
		rnk[i] = 1;
	}
}

int root(int a) {
	while (a != id[a]) {
		id[a] = id[id[a]];
		a = id[a];
	}
	return a;
}

void join(int a, int b) {
	int ia = root(a);
	int ib = root(b);

	if (ia != ib) {
		if (rnk[ia] <= rnk[ib]) {
			rnk[ib] += rnk[ia];
			id[ib] = ia;
		} else {
			rnk[ia] += rnk[ib];
			id[ia] = ib;
		}
	}
}

bool friends(int a, int b) {
	return (root(a) == root(b)) || (root(inv(a)) == root(inv(b)));
}

bool enemy(int a, int b) {
	return (root(a) == root(inv(b))) || (root(inv(a)) == root(b));
}

int main(void) {
	cin >> N;

	buildUF();

	int A, B, T;

	for ( ; cin >> T >> A >> B && !(T == 0 && A == 0 && B == 0); ) {
		if (T == 1) {
			if (enemy(A, B)) {
				printf("%d\n", -1);
			} else {
				join(A, B);
				join(inv(A), inv(B));
			}
		} else if (T == 2) {
			if (friends(A, B)) {
				printf("%d\n", -1);
			} else {
				join(A, inv(B));
				join(B, inv(A));
			}
		} else if (T == 3) {
			printf("%d\n", friends(A, B));
		} else {
			printf("%d\n", enemy(A, B));
		}
	}

    return 0;
}
