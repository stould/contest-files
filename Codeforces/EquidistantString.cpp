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

string S, T;
int N;

int main(void) {
	cin >> S >> T;
	N = (int) S.size();

	string ans = S;

	int ds = 0;
	int dt = 0;

	for (int i = 0; i < N; i++) {
		if (S[i] != T[i]) {
			dt += 1;
		}
	}

	for (int i = 0; i < N; i++) {
		if (ds == dt) {
			break;
		}
		if (ds < dt) {
			if (S[i] != T[i]) {
				ans[i] = T[i];
				ds += 1;
				dt -= 1;
			}
		}
	}

	if (ds != dt) {
		cout << "impossible\n";
	} else {
		cout << ans << "\n";
	}
	return 0;
}
