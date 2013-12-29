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

string S;

int M;

int main(void) {
	cin >> S;

	M = in();

	int A, B;

	int i;
	int j;

	for ( ; M--; ) {
		A = in();
		B = in();

		if (B - A + 1 < 3) {
			cout << "YES\n";
		} else {		
			bool ok = false;;	
			for (i = A - 1; i < B - 3 && i + 3 < (int) S.size(); i++) {
				string sb = S.substr(i, 3);

				if (sb != "zyx" && sb != "xzy" && sb != "yxz") {
					ok = true;
				}
			}

			if (!ok) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
    return 0;
}