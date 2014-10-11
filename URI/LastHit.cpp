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
int A, B, Ad, Bd, H;

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> A >> Ad >> B >> Bd >> H;

		int L = lcm(Ad, Bd);

		int na = L;
		int nb = L;
		int l = -1;

		for (int i = L; H > 0; i++) {
			//printf("%d %d\n", i, H);
			if (i % Ad == 0 && H > 0 && i == na) {
				H -= A;
				l = 0;
				na = i + Ad;
			}
			if (i % Bd == 0 && H > 0 && i == nb) {
				H -= B;
				l = 1;
				nb = i + Bd;
			}
		}
		
		if (l == 0) {
			cout << "Andre\n";
		} else {
			cout << "Beto\n";
		}
	}
    return 0;
}
