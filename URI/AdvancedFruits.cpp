#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

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

const int MAXN = 110; 

string P, Q;
int N, M;
int dp[MAXN][MAXN]; 

string func(int a, int b) {
	if (a == 0 && b == 0) {
		return "";
	} else if (a == 0 && b > 0) {
		return func(a, b - 1) + Q[b - 1];
	} else if (a > 0 && b == 0) {
		return func(a - 1, b) + P[a - 1];
	} else {
		if (P[a - 1] == Q[b - 1]) {
			return func(a - 1, b - 1) + P[a - 1];
		} else {
			if (dp[a][b - 1] < dp[a - 1][b]) {
				return func(a - 1, b) + P[a - 1];
			} else {
				return func(a, b - 1) + Q[b - 1];
			}
		}
	}
} 

int main(void) {
    for ( ; cin >> P >> Q; ) {
		N = (int) P.size();
		M = (int) Q.size();

		memset(dp, 0, sizeof(dp));

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (P[i - 1] == Q[j - 1]) {
					dp[i][j] = dp[max(0, i - 1)][j - 1] + 1;
				}
				
				dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
			}
		}
		cout << func(N, M) << "\n";
    }
    return 0;
}
