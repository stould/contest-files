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

const int MAXP = 20;
const int MOD = 1000000007;

int T;
int P, L, Q;

vector<vector<Int> > multiply(vector<vector<Int> > a, vector<vector<Int> > b) {
	vector<vector<Int> > res(P, vector<Int>(P));
	for(int i = 0; i < P; i++) {
		for(int j = 0; j < P; j++) {
			int sum = 0;
			for (int k = 0; k < P; k++) {
				sum = (((sum % MOD) + (a[i][k] * b[k][j]) % MOD) + MOD) % MOD;
			}
			res[i][j] = sum;
		}
	}
	return res;
}

vector<vector<Int> > binPow(vector<vector<Int> > a, Int n) {
	if (n == 1) {
		return a;
	} else if ((n & 1) != 0) {
		return multiply(a, binPow(a, n - 1));
	} else {
		vector<vector<Int> > b = binPow(a, n / 2);
		return multiply(b, b);
	}
}


int main(void) {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case %d:\n", t);

		scanf("%d%d", &P, &L);

		vector<vector<Int> > base(P, vector<Int>(P, 0));

		for (int i = 0; i < L; i++) {
			int A, B;
			scanf("%d%d", &A, &B);
			A--; B--;
			base[A][B] = 1;
		}
		scanf("%d", &Q);
		for ( ; Q--; ) {
			int A, B;
			Int G;
			scanf("%d%d%lld", &A, &B, &G);

			vector<vector<Int> > ans = binPow(base, G);
			
			printf("%d\n", (int) ans[A - 1][B - 1]);
		}
	}
    return 0;
}
