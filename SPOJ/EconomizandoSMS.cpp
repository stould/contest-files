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

int N, L, G;
string S[5050];

int main(void) {
	for ( ; cin >> N >> L >> G && (N + L + G != 0); ) {
		cin.ignore();
		for (int i = 0; i < N; i++) {
			getline(cin, S[i]);
		}
		int El = 0, Eg = 0;

		for (int i = 0; i < N; i++) {
			int inc = 0;

			if (S[i][0] == 'G') {
				inc = 8;
			} else {
				inc = 7;
			}			
			
			int used = 0;

			int j = i;

			while (j < N && S[i][0] == S[j][0]) {
				int next_used = used + S[j].size() - inc;
				if (j != i) next_used += 1;

				if (next_used > 160) {
					break;
				}
				used = next_used;
				j += 1;
			}
			if (S[i][0] == 'G') {
				Eg += (j - i - 1) * G;
			} else {
				El += (j - i - 1) * L;
			}
			i = j - 1;
		}
		printf("%d %d\n", El, Eg);
	}
    return 0;
}
