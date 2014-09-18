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

const int MAXN = 500005;

int N, K;
int P[MAXN], S[MAXN];

int main(void) {
	cin >> N >> K;

	int ans = INT_MAX, id = -1;

	for (int i = 1; i <= N; i++) {
		cin >> P[i];
		S[i] = S[i - 1] + P[i];
		
		if (i - K >= 0) {
			int s = S[i] - S[i - K];

			if (s < ans) {
				ans = s;
				id = i - K + 1;
			}
		}
	}

	cout << id << "\n";
    return 0;
}
