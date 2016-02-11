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

int A[3], B[3], C[3];

int main(void) {
	for (int i = 0; i < 2; i++) {
		cin >> A[i] >> B[i] >> C[i];
	}

	int extra = 0;

	extra += max(0, (A[0] - A[1]) / 2);
	extra += max(0, (B[0] - B[1]) / 2);
	extra += max(0, (C[0] - C[1]) / 2);

	if (A[1] > A[0]) {
		int need = A[1] - A[0];

		A[0] += need;
		extra -= need;
	}
	if (B[1] > B[0]) {
		int need = B[1] - B[0];

		B[0] += need;
		extra -= need;
	}
	if (C[1] > C[0]) {
		int need = C[1] - C[0];

		C[0] += need;
		extra -= need;
	}

	if (extra >= 0 && A[0] >= A[1] && B[0] >= B[1] && C[0] >= C[1]) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
		
	return 0;
}
