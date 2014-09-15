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

typedef unsigned long long uInt;
typedef long long Int;
typedef unsigned uint;

int T, N;
uInt M[22][22], mult[22][22];
int best[22];

int func(Int x) {
	int len = 0;

	while (x > 0LL) {
		len += 1;
		x /= 10LL;
	}

	return len;
}

int main(void) {
	cin >> T;
	int test = 4;

	for ( ; T--; ) {
		cout << "Quadrado da matriz #" << (test++) << ":" << endl;
		cin >> N;
		

		memset(best, 0LL, sizeof(best));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> M[i][j];
				mult[i][j] = (uInt) (M[i][j] * (uInt) M[i][j]);
				chmax(best[j], func(mult[i][j]));
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int curr_len = func(mult[i][j]);
				
				for (int k = 0; k < best[j] - curr_len; k++) {
					cout << " ";
				}
				cout << mult[i][j];
			}
			cout << endl;
		}
		cout << endl;		
	}
    return 0;
}
