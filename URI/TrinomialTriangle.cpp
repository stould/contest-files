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

int R;
int M[25][25];
/*
1
1 1 1
1 2 3 2 1
1 3 6 7 6 3 1
*/
int main(void) {
	M[0][0] = 1;

	for (int i = 1; i <= 20; i++) {
		M[i][0] = 1;
		for (int j = 1; j <= i + i; j++) {
			if (j == i + i) {
				M[i][j] = 1;
			} else {
				M[i][j] = M[i-1][j] + M[i-1][j-1];
				if (j - 2 >= 0) {
					M[i][j] += M[i-1][j-2];
				}
			}
		}
	}

	while (cin >> R) {
		Int ans = 0LL;

		for (int i = 0; i <= R+2; i++) {
			ans += M[R][i];
		}
		cout << ans << endl;
	}
	return 0;
}
