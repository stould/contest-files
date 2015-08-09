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

int R, P, S;
double dp[110][110][110];

int main(void) {
	cin >> R >> P >> S;

	dp[R][P][S] = 1.0;
	
	for (int f = R + S + P; f >= 0; f--) {
		for (int j = P; j >= 0; j--) {
			for (int k = S; k >= 0; k--) {
				int i = f - j - k;

				if (i < 0 or i > R) continue;
				if (i == 0 && k == 0) continue;
				if (i == 0 && j == 0) continue;
				if (j == 0 && k == 0) continue;
				
								
				int rW = i * k;
				int pW = j * i;
				int sW = k * j;

				int all = rW + pW + sW;
				
				if (k > 0) {
					dp[i][j][k - 1] += dp[i][j][k] * (sW / (double) all);
				}
				if (i > 0) {
					dp[i - 1][j][k] += dp[i][j][k] * (rW / (double) all);
				}
				if (j > 0) {
					dp[i][j - 1][k] += dp[i][j][k] * (pW / (double) all);
				}
			}
		}
	}

	double r = 0, p = 0, s = 0;
	
	for (int i = 1; i <= R; i++) {
		r += dp[i][0][0];		
	}
	for (int i = 1; i <= P; i++) {
		p += dp[0][i][0];
	}
	for (int i = 1; i <= S; i++) {
		s += dp[0][0][i];
	}

	cout << fixed << setprecision(12) << r << " " << p << " " << s << endl;
	
	return 0;
}
