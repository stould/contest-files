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

int N;
int P[MAXN], S[MAXN];

int main(void) {
	freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i] >> S[i];
	}

	int ans = 0;
	int curr = INT_MAX;
	
	for (int i = N - 1; i >= 0; i--) {
		if (S[i] <= curr) {
			ans += 1;
			curr = S[i];
		}
	}

	cout << ans << "\n";
	
    return 0;
}
