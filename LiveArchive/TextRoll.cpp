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

int N;
string S[MAXN];

int main(void) {
	while (cin >> N && N != 0) {
		int mlen = 0;
		getline(cin, S[0]);
		for (int i = 0; i < N; i++) {
			getline(cin, S[i]);
			chmax(mlen, (int) S[i].size());

		}
		for (int i = 0; i < N; i++) {
			while (mlen > (int) S[i].size()) {
				S[i] += " ";
			}
		}
		int i = 0, j = 0;

		while (i < N) {
			if (j < mlen) {
				if (S[i][j] == ' ') {
					i +=  1;
				} else {
					j += 1;
				}
			} else {
				break;
			}
		}
		cout << j + 1 << "\n";
	}
	return 0;
}
