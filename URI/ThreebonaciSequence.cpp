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

int N;
Int F[100];

int main(void) {
	F[0] = 0;
	F[1] = 1;
	
	for (int i = 2; i < 100; i++) {
		F[i] = F[i - 1] + F[i - 2];
		cout << F[i] << endl;
	}
	int cnt = 0;
	
	for (int i = 0; i < 100; i++) {
		if (F[i] % 3 == 0) {
			Int cp = F[i];
			bool ok = false;
			
			while (cp > 0) {
				int d = cp % 10;
				if (d == 3) ok = true;
				cp /= 10;
			}
			if (ok) {
				cout << cnt++ << " " << F[i] << endl;
			}
		}

	}
	for ( ; cin >> N; ) {
		
	}
    return 0;
}
