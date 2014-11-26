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

int N, M;
string S;
int C[5];

int main(void) {
	cin >> N >> S;
	M = (int) S.size();
	
	Int ans = 0LL;

	for (int i = 0; i < M; i++) {
		int l = S[i] - '0';
		if (C[1] + 2 * C[2] + l <= N) {
			if (l == 1) {
				C[1] += 1;
			} else {
				C[2] += 1;
			}
		} else {
			if (l == 1) {
				if (C[2] > 0) {
					C[1] += 1;
					C[2] -= 1;
				}
			} 
		}	
	
		ans += C[1] + C[2];
	}

	cout << ans << "\n";

    return 0;
}
