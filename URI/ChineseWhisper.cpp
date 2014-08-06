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

int T;
string S[5];

int main(void) {
	cin >> T;
	cin.ignore();

	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 3; i++) {
			getline(cin, S[i]);
		}
		int N = (int) S[0].size();
		int w1 = 0, w2 = 0;
		int i1 = -1, i2 = -1;

		for (int i = 0; i < N; i++) {
			if (S[1][i] == S[0][i]) {
				w1 += 1;
				if (i1 == -1 && S[2][i] != S[0][i]) i1 = i;
			}
			if (S[2][i] == S[0][i]) {
				w2 += 1;
				if (i2 == -1 && S[1][i] != S[0][i]) i2 = i;
			}
		}
		cout << "Instancia " << t << "\n";
		
		if (w1 != w2) {
			cout << ((w1 > w2) ? "time 1\n" : "time 2\n");
		} else {
			if (i1 != i2) {
				cout << ((i1 < i2) ? "time 1\n" : "time 2\n");
			} else {
				cout << "empate\n";
			}
		}
		cout << "\n";
	}

    return 0;
}
