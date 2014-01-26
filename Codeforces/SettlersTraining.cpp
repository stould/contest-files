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

int N, K;

vector<int> soldier;

int main(void) {
	cin >> N >> K;

	soldier.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> soldier[i];
	}

	int ans = 0;

	for ( ; ; ) {
		set<int> memo;

		for (int i = 0; i < N; i++) {
			if (!memo.count(soldier[i]) && soldier[i] < K) {
				memo.insert(soldier[i]);
				soldier[i] += 1;
			}
		}
		if (memo.empty()) break;
		ans += 1;
	}
	cout << ans << "\n";
    return 0;
}
