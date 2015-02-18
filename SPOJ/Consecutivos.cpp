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

const int MAXN = 10004;
int N;
int P[MAXN];

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		int j = i + 1;
		int t = 1;

		for ( ; P[j] == P[i]; ) {
			j++;
			t++;
		}

		ans = max(ans, t);
	}

	cout << ans << "\n";
    return 0;
}
