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

const int MAXN = 1010;

int T, N;
string S[MAXN];

bool func(string& a, string& b) {
	string buff = a + b;
	int N = (int) buff.size();

	for (int i = 0; i < N / 2; i++) {
		if (buff[i] != buff[N - i - 1]) {
			return false;
		}
	}

	return true;
}

int main(void) {
	cin >> T;

	for (int x = 1; x <= T; x++) {
		cin >> N;	

		for (int i = 0; i < N; i++) {
			cin >> S[i];
		}

		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i != j) {
					if (func(S[i], S[j])) {
						ans += 1;
					}
				}
			}
		}

		cout << "Case #" << x << ": " << ans << "\n";
	}
    return 0;
}
