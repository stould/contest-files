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

const int MAXN = 204;

int N;
int A, B;
string C;

bool mat[27][MAXN][MAXN];

int main(void) {
	for ( ; cin >> N && N != 0; ) {
		memset(mat, false, sizeof(mat));

		int M = 0;

		for ( ; cin >> A >> B && !(A == 0 && B == 0); ) {
			cin >> C;
			
			for (int i = 0; i < (int) C.size(); i++) {
				mat[C[i] - 'a'][A][B] = true;
			}

			M = max(M, max(A, B));
		}

		for (int c = 0; c < 26; c++) {
			for (int k = 0; k <= M; k++) {
				for (int i = 0; i <= M; i++) {
					for (int j = 0; j <= M; j++) {
						mat[c][i][j] |= (mat[c][i][k] & mat[c][k][j]);
					}
				}
			} 
		}

		for ( ; cin >> A >> B && !(A == 0 && B == 0); ) {
			string ans = "";

			for (int i = 0; i < 26; i++) {
				if (mat[i][A][B]) {
					ans += 'a' + i;
				}
			}
			
			if (ans == "") {
				ans = "-";
			}			

			cout << ans << "\n";
		}
		cout << "\n";
	}
    return 0;
}
