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

const int MAXN = 55 * 55;
const Int MOD = 1000000007LL;
int N, M;
int dp[60][60];
int bin[MAXN][MAXN];

int main(void) {
	cin >> N >> M;

	char C;

	bin[0][0] = 1ll;
 
	for (int n = 1; n < MAXN; n++) {
		bin[n][0] = 1;
		bin[n][n] = 1;
		
		for (int k = 1; k < n; k++) {
			bin[n][k] = bin[n - 1][k] + bin[n - 1][k - 1];
			if (bin[n][k] >= MOD) {
				bin[n][k] -= MOD;
			}
			bin[n][k] %= MOD;
		}
	} 
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> C;
			
			if (C == '#') {
				dp[i][j] += 1;
			}
		}		
	}

	int A, B, X, Y;
	
	while (cin >> A >> B >> X >> Y) {
		int all = (X - A + 1) * (Y - B + 1);
		int cnt = 0;

		for (int i = A; i <= X; i++) {
			for (int j = B; j <= Y; j++) {
				cnt += dp[i][j];
			}
		}

		Int ans = bin[all][cnt] % MOD;
		
		cout << ans - 1 << endl;
	}
	
	return 0;
}
