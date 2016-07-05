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

const int MAXN = 100005;

int N, M;
double dp[MAXN];
bool state[MAXN];

double func(int pos) {
	if (pos == 0) {
		return 1.0;
	} else {
		double& ans = dp[pos];
		
		if (!state[pos]) {		
			ans = 0.0;
			state[pos] = true;
			
			for (int i = 1; i <= M; i++) {
				
				ans *= i * (1 / (double) M) * func(pos - 1);
			}
		}
		
		return ans;
	}
}

int main(void) {
	cin >> M >> N;
	memset(state, false, sizeof(state));
	cout << fixed << setprecision(10) << func(N) << "\n";
	return 0;
}
