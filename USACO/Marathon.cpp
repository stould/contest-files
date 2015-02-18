#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>

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

const int MAXN = 100010;
const Int INF = 10010100110101000LL;

int N;
int X[MAXN], Y[MAXN];

int main(void) {
	freopen("marathon.in", "r", stdin);
	freopen("marathon.out", "w", stdout);
	
	cin >> N;
	
	Int sum = 0LL;
	
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];

		if (i > 0) {
			sum += abs(X[i] - X[i - 1]) + abs(Y[i] - Y[i - 1]);
		}
	}

	Int ans = 0;

	for (int i = 1; i < N - 1; i++) {
		Int skip = abs(X[i + 1] - X[i - 1]) + abs(Y[i + 1] - Y[i - 1]);
		Int curr = abs(X[i - 1] - X[i]) + abs(Y[i - 1] - Y[i]) + abs(X[i] - X[i + 1]) + abs(Y[i] - Y[i + 1]);

		chmax(ans, curr - skip);		
	}
	
	cout << sum - ans << "\n";
	
    return 0;
}
