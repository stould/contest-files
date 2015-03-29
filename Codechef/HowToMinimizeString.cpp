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

int T, N;
string S;

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> S;

		char curr = 'Z', pos = -1;

		for (char c = 'A'; c <= 'Z'; c++) {
			pos = -1;
			for (int i = 0; i < S.size(); i++) {
				if (S[i] == c) {
					curr = S[i];
					pos = i;
				}
			}
			if (pos != -1) {
				bool ok = false;
				
				for (int i = 0; i < pos; i++) {
					if (S[i] > c) {
						ok = true;
						break;
					}
				}
				if (ok) break;
			}
		}

		S = S.substr(0, pos) + S.substr(pos + 1, S.size() - pos - 1);

		for (int i = 0; i < S.size(); i++) {
			if (S[i] > curr) {
				S = S.substr(0, i) + curr + S.substr(i, S.size() - i);
				break;					
			}
		}
		cout << S << "\n";
	}
    return 0;
}
