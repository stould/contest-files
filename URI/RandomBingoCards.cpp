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

int C[30], P[30];
int L[6], R[6];

int main(void) {
	L[0] = 1;
	R[0] = 15;
	
	for (int i = 1; i <= 5; i++) {
		L[i] = L[i - 1] + 15;
		R[i] = R[i - 1] + 15;
	}
	
	for ( ; cin >> C[0]; ) {
		for (int i = 1; i < 25; i++) {
			if (i == 12) {
				C[i] = 45;
			} else {
				cin >> C[i];
			}
		}

		bool ok = true;
		
		for (int i = 0; ok && i < 24; i++) {
			//cout << L[i % 5] << " " << R[i % 5] << " => " << C[i] << endl;
			if (!(C[i] >= L[i % 5] && C[i] <= R[i % 5])) {
				ok = false;
			}
		}

		if (ok) {
			cout << "OK" << endl;
		} else {
			sort(C, C + 25);

			for (int i = 0 ; i < 25; i++) {
				P[i] = C[i];
			}

			int pos = 0;
			
			for (int i = 0 ; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					C[i + j * 5] = P[pos++];
				}
			}

			bool reci = true;
			
			for (int i = 0; reci && i < 24; i++) {
				if (!(C[i] >= L[i % 5] && C[i] <= R[i % 5])) {
					reci = false;
				}
			}
			if (reci) {
				cout << "RECICLAVEL" << endl;
			} else {
				cout << "DESCARTAVEL" << endl;
			}
		}
	}
    return 0;
}
