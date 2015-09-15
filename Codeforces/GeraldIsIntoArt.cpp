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
typedef unsigned uint;

int L[5], R[5];

bool ok(int a, int b, int x, int y) {
	if ((a + x <= L[0] && max(b, y) <= R[0]) or (a + x <= R[0] && max(b, y) <= L[0])) {
		return true;
	} else if ((a + y <= L[0] && max(b, x) <= R[0]) or (a + y <= R[0] && max(b, x) <= L[0])) {
		//cout << a << " " << b << " " << x << " " << y << endl;
		return true;
	} else {
		return false;
	}
}

int main(void) {
	for (int i = 0; i < 3; i++) {
		cin >> L[i] >> R[i];
	}
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= 2; j++) {
			if (i != j) {
				if (ok(L[i], R[i], L[j], R[j]) or ok(R[i], L[i], R[j], L[j])) {
					cout << "YES" << endl;
					return 0;
				}
			}
		}
	}

	
	cout << "NO" << endl;
	
	return 0;
}
