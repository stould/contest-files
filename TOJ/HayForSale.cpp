#include <iostream>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 50050;

int C, N;
int P[5005];
bool dp[MAXN];

int main(void) {
	cin >> C >> N;

	dp[0] = true;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = C; j >= P[i]; j--) {
			dp[j] |= dp[j - P[i]];
		}
	}
	int ans = C;

	while (!dp[ans] && ans > 0) {
		ans -= 1;
	}
	cout << ans << "\n";
    return 0;
}
