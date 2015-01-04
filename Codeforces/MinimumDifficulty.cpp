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

int N;
int P[MAXN];

int main(void) {
	cin >> N;

	int ans = INT_MAX;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	for (int i = 1; i < N - 1; i++) {
		int curr = 0;
		
		for (int j = 1; j < N; j++) {
			if (i == j) {
				curr = max(curr, P[j + 1] - P[j - 1]);
			} else if (i + 1 == j) {
				curr = max(curr, P[j] - P[j - 2]);
			} else {
				curr = max(curr, P[j] - P[j - 1]);
			}
		}
		ans = min(ans, curr);
	}

	cout << ans << "\n";
	
    return 0;
}
