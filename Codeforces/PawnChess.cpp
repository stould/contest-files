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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

string S[10];

int main(void) {
	for (int i = 0; i < 8; i++) {
		cin >> S[i];
	}

	int bestA = 10, bestB = 10;
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (S[i][j] == 'W') {
				bool ok = true;

				for (int k = i - 1; k >= 0; k--) {
					if (S[k][j] != '.') ok = false;
				}

				if (ok) chmin(bestA, i);
			}
			if (S[i][j] == 'B') {
				bool ok = true;
	
				for (int k = i + 1; k < 8; k++) {
					if (S[k][j] != '.') ok = false;
				}

				if (ok) chmin(bestB, 8 - i);
			}
		}
	}
	//cout << bestA << "  " << bestB << "\n";
	if (bestA < bestB) {
		cout << "A\n";
	} else {
		cout << "B\n";
	}
			
	return 0;
}
