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

const int MAXN = 2;
const int MAXM = 2;
const Int MOD = 1000000LL;

Int N, K, L;

struct Matrix {
	int N, M;
	Int buff[MAXN][MAXM];

	Matrix(int _N, int _M): N(_N), M(_M) {		
		memset(buff, 0LL, sizeof(buff));
	}

	Matrix& operator=(const Matrix& other) {		
		for (int i = 0; i < other.N; i++) {
			for (int j = 0; j < other.M; j++) {
				this->buff[i][j] = other.buff[i][j] % MOD;
			}
		}
		return *this;
	}
	
	Matrix operator*(const Matrix other) const {
		Matrix ans(this->N, other.M);
		
		cout << "Multiply \n";
		
		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < this->M; j++) {
				cout << this->buff[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "With\n";
		for (int i = 0; i < other.N; i++) {
			for (int j = 0; j < other.M; j++) {
				cout << other.buff[i][j] << " ";
			}
			cout << "\n";
		}
		
		for (int i = 0; i < this->N; i++) {
			for (int j = 0; j < other.M; j++) {
				for (int k = 0; k < 2; k++) {
					ans.buff[i][j] = ((ans.buff[i][j] % MOD) + ((buff[i][k] * other.buff[k][j]) % MOD)) % MOD;
				}
			}
		}
		
		return ans;
	} 
	Matrix powto(Int power) {
		Matrix ans(this->N, this->M);

		for (int i = 0; i < ans.N; i++) {
			for (int j = 0; j < ans.M; j++) {
				ans.buff[i][j] = this->buff[i][j] % MOD;
			}
		}
		
		while (power > 1LL) {
			if (power % 2 == 1) {
				ans = ans * (*this);
			}
			power /= 2;
			ans = ans * ans;
		}
		return ans;
	}
};

int main(void) {
	for ( ; scanf("%lld%lld%lld", &N, &K, &L) == 3; ) {
		N /= 5;
		
		Matrix base(1, 2);
		Matrix tran(2, 2);
		
		base.buff[0][0] = 1LL;
		base.buff[0][1] = K;

		tran.buff[0][0] = 0LL;
		tran.buff[0][1] = L;
		tran.buff[1][0] = 1LL;
		tran.buff[1][1] = K;		
		
		Matrix nova = tran.powto(N);

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				cout << nova.buff[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		Matrix ans = base * nova;

		cout << "Ans\n";
		for (int i = 0; i < ans.N; i++) {
			for (int j = 0; j < ans.M; j++) {
				cout << ans.buff[i][j] << " ";
			}
			cout << "\n";
		}

		string ans_s = to_string(ans.buff[0][0] % MOD);

		for ( ; ans_s.size() < 6; ) {
			ans_s = "0" + ans_s;
		}
		printf("%s\n", ans_s.c_str());
	}
    return 0;
}
