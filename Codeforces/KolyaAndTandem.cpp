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

string S;
int K;

int main(void) {
	cin >> S >> K;
	int N = (int) S.size();
	
	for (int i = 0; i < K; i++) {
		S += '.';
	}
	N += K;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 1; i + j <= N; j++) {
			if (j % 2 == 0) {
				string t = S.substr(i, j);
				int len = (j + 1) / 2;
				
				bool ok = true;

				for (int k = 0; k < len; k++) {
					if (S[i + k] != S[i + k + len] && S[i + k + len] != '.') {
						ok = false;
					}
				}

				if (ok) {
					ans = max(ans, 2 * len);
				}
			}
		}
	}
	cout << ans << "\n";
    return 0;
}
