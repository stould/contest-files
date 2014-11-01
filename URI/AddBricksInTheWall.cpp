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
int P[10][10];

bool check(void) {	
	for (int i = 7; i >= 1; i--) {
		for (int j = 0; j <= i; j++) {
			if (!(i % 2 == 0 && j % 2 == 0)) {
				P[i][j] = P[i + 1][j] + P[i + 1][j + 1];
			}
			if (P[i][j] != P[i + 1][j] + P[i + 1][j + 1]) {
				return false;
			}
		}
	} 				

	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);

	cin >> T;
	
	for ( ; T--; ) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j <= i; j++) {
				if (i % 2 == 0 && j % 2 == 0) {
					cin >> P[i][j];
				}
			} 
		}
		const int V = 30;
		
		P[8][1] = (P[6][0] - P[8][0] - P[8][2]) / 2;
		P[8][3] = (P[6][2] - P[8][2] - P[8][4]) / 2;
		P[8][5] = (P[6][4] - P[8][4] - P[8][6]) / 2;
		P[8][7] = (P[6][6] - P[8][6] - P[8][8]) / 2;
						
		
		check();

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j <= i; j++) {
				if (j) cout << " ";
				cout << P[i][j];
			}
			cout << "\n";
		}
	}
	
    return 0;
}
