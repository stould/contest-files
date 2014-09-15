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

int N;
string S;

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> S;

		char best = 0;
		bool ok = true;

		for (int j = 0; j < (int) S.size(); j++) {
			char curr = tolower(S[j]);
			if (curr <= best) {
				ok = false;
			}
			best = curr;
		}

		cout << S << ": " << (ok ? "O" : "N") << "\n";
	}
    return 0;
}
