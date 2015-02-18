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

int N;
string S;

int main(void) {
	cin >> S;

	int ans = 0;

	N = (int) S.size();

	for (int i = 0; i < N - 4; i++) {
		if (S.substr(i, 4) == "bear") {
			printf("%d %d\n", i, N - (i + 3));
			ans += i + (N - (i + 3));
		}
	}

	printf("%d\n", ans);

    return 0;
}
