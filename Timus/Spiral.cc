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

int N, M;

int main(void) {
	cin >> N >> M;

	Int ans = min(2LL * (Int) (N - 1), 2LL * (Int) (M - 1));

	if (N > M) ans += 1LL;

	cout << ans << "\n";

    return 0;
}
