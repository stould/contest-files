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

const int MAXN = 110;

int N, D;
int P[MAXN];

int main(void) {
	cin >> N >> D;

	int sum = 0;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
		sum += P[i];
	}
	int s = 0, joke = 0;

	s = sum + 10 * (N - 1);
	joke += 2 * (N - 1);

	while (s + 5 <= D) {
		s += 5;
		joke += 1;
	}

	if (s > D) joke = -1;

	cout << joke << "\n";
    return 0;
}
