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
typedef vector<vector<Int> > matrix;

const int MAXN = 10;
const int MAXM = 10;
const Int MOD = 1000000LL;

Int N, K, L;

#define REP(i,n) for (int i = 0; i < n; i++)

typedef vector<vector<Int> > matrix;

matrix mul(matrix A, matrix B) {
	matrix C(2, vector<Int>(2));
	REP(i, 2) REP(j, 2) REP(k, 2)
		C[i][j] = (C[i][j] + (A[i][k] % MOD) * (B[k][j] % MOD)) % MOD;
	return C;
}

matrix pow(matrix A, Int p) {
	if (p == 1) {
		return A;
	}
	if (p % 2) {
		return mul(A, pow(A, p-1));
	}
	matrix X = pow(A, p/2);
	return mul(X, X);
}

int main(void) {
	for ( ; scanf("%lld%lld%lld", &N, &K, &L) == 3; ) {
		N /= 5;
		
		matrix base(2, vector<Int>(2));
		matrix tran(2, vector<Int>(2));
		
		base[0][0] = 1LL;
		base[0][1] = K;

		tran[0][0] = 0LL;
		tran[0][1] = L;
		tran[1][0] = 1LL;
		tran[1][1] = K;		

		matrix nova = pow(tran, N);
		matrix ans = mul(base, nova);

		string ans_s = to_string(ans[0][0] % MOD);

		for ( ; ans_s.size() < 6; ) {
			ans_s = "0" + ans_s;
		}
		printf("%s\n", ans_s.c_str());
	}
    return 0;
}
