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

int H, D, F;
double U;

int main(void) {
	for ( ; cin >> H >> U >> D >> F; ) {
		if (H == 0) {
			break;
		}
		
		double pos = 0.0;
		double climb = F * U / 100.0;

		for (int i = 1; ; i++) {
			pos += U;

			if (pos > H) {
				cout << "success on day " << i << "\n";
				break;
			}

			pos -= D;
			U -= climb;
			
			if (pos < 0.0) {
				cout << "failure on day " << i << "\n";
				break;
			}
		}
	}
	
    return 0;
}
