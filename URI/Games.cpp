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
char buff[110];

int main(void) {
	scanf("%d", &T);

	for ( ; T--; ) {
		scanf("%d", &N);

		vector<string> S(N);

		cin.ignore();

		for (int i = 0; i < N; i++) {
			getline(cin, S[i]);
		}

		vector<string> srt = S;

		int ans = 0;

		for ( ; ; ) {
			string sm = S[0];

			bool done = false;

			for (int i = 1; !done && i < N; i++) {
				if (S[i] < sm) {
					string tmp = S[i];

					S.erase(S.begin() + i);
					
					for (int j = 0; !done && j <= i; j++) {
						if (S[j] > tmp || j == i) {
							ans += 1;
							S.insert(S.begin() + j, tmp);
							done = true;
							break;
						}
					}
					break;
				} else {
					sm = max(sm, S[i]);
				}
			}
			if (!done) break;
		}

		printf("%d\n", ans);
	}
    return 0;
}
