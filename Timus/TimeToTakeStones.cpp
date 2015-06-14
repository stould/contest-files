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

const int MAXN = 10005;

int N, M;
int P[55];
int dp[MAXN];

int flip(int x) {
	if (x == 1) return 2;
	return 1;
}

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> P[i];
	}

	dp[0] = 1;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (i - P[j] >= 0 && dp[i - P[j]] == 0) {
				dp[i] = 1;
				break;
			}
		}
	}

	cout << 2 - dp[N] << endl;
	
	return 0;
}
