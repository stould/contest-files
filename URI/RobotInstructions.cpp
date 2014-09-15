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
string S[110];

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> T;

	for ( ; T--; ) {
		cin >> N;
		int p = 0;

		string junk;

		for (int i = 0; i < N; i++) {
			cin >> S[i];
			if (S[i][0] == 'L') {
				p -= 1;
			} else if (S[i][0] == 'R') {
				p += 1;
			} else {
				cin >> junk;
				cin >> S[i];
				int pos = i;

				for ( ; isdigit(S[pos][0]) ; ) {
					pos = std::stoi(S[pos]) - 1;
				}
				if (S[pos][0] == 'L') {
					p -= 1;
				} else {
					p += 1;
				}
			}
		}
		cout << p << "\n";
	}

    return 0;
}
