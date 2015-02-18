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

int C, N;
int T[100005];

int main(void) {
	for ( ; cin >> C >> N; ) {
		bool ok = false;

		int p = C / N;

		for (int i = 0; i < N; i++) {
			cin >> T[i];
		}

		T[N] = C + T[0];

		for (int i = T[0]; i < T[1]; i++) {
			bool fine = true;
			int pos = i;
			
			for (int j = 1; fine && j <= N; j++) {
				if (pos < T[j] && pos + p >= T[j]) {
					pos += p;
				} else {
					fine = false;
				}
			}
			if (fine) {
				ok = true;
				break;
			}			
		}

		if (ok) {
			cout << "S\n";
		} else {
			cout << "N\n";
		}
	}
	
    return 0;
}
