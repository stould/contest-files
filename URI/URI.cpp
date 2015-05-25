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

int main(void) {
	while (cin >> N && N != 0) {
		int pu = 0, pr = 0, pi = 0;
		
		for (int i = 0; i < N; i++) {
			int U, R, I;
			cin >> U >> R >> I;

			if ((U & (U - 1)) == 0) {
				pu += 1;
				if (U > R && U > I) {
					pu += 1;
				}
			}
			if ((R & (R - 1)) == 0) {
				pr += 1;
				if (R > U && R > I) {
					pr += 1;
				}
			}
			if ((I & (I - 1)) == 0) {
				pi += 1;
				if (I > U && I > R) {
					pi += 1;
				}
			}
		}

		if (pu > pr && pu > pi) {
			cout << "Uilton\n";
		} else if (pr > pu && pr > pi) {
			cout << "Rita\n";
		} else if (pi > pu && pi > pr) {
			cout << "Ingred\n";
		} else {
			cout << "URI\n";
		}
	}
    return 0;
}
