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

const int K = 5;
const Int MOD = 13371337LL;
Int N;
Int A[6];

vector<vector<Int> > multiply(vector<vector<Int> > a, vector<vector<Int> > b) {
	vector<vector<Int> > res(K, vector<Int>(K));
	for(int i = 0; i < K; i++) {
		for(int j = 0; j < K; j++) {
			int sum = 0;
			for (int k = 0; k < K; k++) {
				sum = ((sum % MOD) + ((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD) % MOD;
				sum = (sum + MOD) % MOD;
			}
			res[i][j] = ((sum + MOD) % MOD);
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
	for ( ; scanf("%lld", &N) == 1 && N != 0; ) {
		vector<Int> initial(K);
		for (int i = 0; i < 4; i++) {
			scanf("%lld", &A[i]);
			initial[i] = (Int) A[i];
			initial[4] += initial[i];
		}
		
		vector<vector<Int> > trans;

		for (int i = 0; i < 5; i++) {
			trans.push_back(vector<Int>());
			for (int j = 0; j < 5; j++) {
				trans[i].push_back(0LL);
			}
		}

		
		trans[1][0] = 1LL;
		trans[2][1] = 1LL;
		trans[3][2] = 1LL;
		trans[4][3] = 1LL;

		trans[0][4] = -1LL;
		trans[4][4] = 2LL;
		
		vector<vector<Int> > ansT = binPow(trans, (Int) N - 4);
		Int ans[5];

		for (int i = 0; i < 5; i++) {
			ans[i] = 0LL;
			for (int j = 0; j < 5; j++) {								
				ans[i] = ((ans[i] % MOD) + ((initial[j] % MOD) * (ansT[j][i] % MOD)) % MOD) % MOD;
				ans[i] = (ans[i] + MOD) % MOD;
			}
		}
		printf("%lld\n", ans[4]);
		
	}
    return 0;
}
