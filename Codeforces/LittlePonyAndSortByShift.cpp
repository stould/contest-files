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

const int MAXN = 100005;

int N;
int P[MAXN];

bool isSorted(int l, int r) {
	for (int i = l + 1; i <= r; i++) {
		if (P[i] < P[i - 1]) {
			return false;
		}
	}
	return true;
}

int main(void) {
	while (cin >> N) {
		int until = 0;

		for (int i = 0; i < N; i++) {
			cin >> P[i];
		}
		for (int i = 1; i < N; i++) {			
			if (P[i - 1] > P[i]) {
				break;
			}
			until = i;
		}

		if (isSorted(0, N - 1)) {
			cout << 0 << "\n";
		} else {
			bool isRev = true;
			//cerr << "un " << until << "\n";
			
			for (int i = until + 2; i < N; i++) {
				if (P[i - 1] > P[i]) {
					isRev = false;
					//					cerr << "Fail " << P[i - 1] << " " << P[i] << "\n";
				}
			}
			
			if (isRev) {				
				int novo[N];
				int pos = 0;
				for (int i = until + 1; i < N; i++) {
					novo[pos++] = P[i];
				}
				for (int i = 0; i <= until; i++) {
					novo[pos++] = P[i];
				}
				bool equal = true;
				
				sort(P, P + N);

				for (int i = 0; i < N; i++) {
					if (P[i] != novo[i]) {
						equal = false;
					}
				}
				
				if (equal) {
					cout << N - until - 1 << "\n";
				} else {
					cout << "-1\n";
				}
			} else {
				cout << "-1\n";
			}
		}
	}
	return 0;
}
