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

const int MAXN = 1000005;

int N;
int P[MAXN];

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	sort(P, P + N);
	int ans = P[0];
	
	for (int i = 0; i < N; i++) {
		ans = max(ans, P[i] - P[0]);
	}

	cout << ans << endl;

    return 0;
}
