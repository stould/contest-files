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

const int MAXN = 1010;

int N, M;
int P[MAXN];

int dp[MAXN][120];

int func(int id, int last) {
	if (id == N) {
		return last == M ? 0 : INF;
	} else {
		int& ans = dp[id][last];
		
		if (ans == -1) {
			ans = INF;

		}

		return ans;
	}
}

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	
	

    return 0;
}
