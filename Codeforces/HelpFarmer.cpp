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

Int N;
Int A, B;

void funcA(Int i, Int j) {
	Int k = N / (i * j);
	
	if (i * j * k == N) {
		chmax(A, ((i + 2) * (j + 2) * (k + 1)) - i * j * k);
		chmin(B, ((i + 2) * (j + 2) * (k + 1)) - i * j * k);

		chmax(A, ((i + 2) * (j + 1) * (k + 2)) - i * j * k);
		chmin(B, ((i + 2) * (j + 1) * (k + 2)) - i * j * k);

		chmax(A, ((i + 1) * (j +  2) * (k + 2)) - i * j * k);
		chmin(B, ((i + 1) * (j +  2) * (k + 2)) - i * j * k);
	}
}

int main(void) {
	cin >> N;

	A = LLONG_MIN;
	B = LLONG_MAX;

	for (Int i = 1; i * i * i <= N; i++) {
		if (N % i == 0) {
			for (Int j = i; j * j <= N / i; j++) {				
				if ((N / i) % j == 0) {
					funcA(i, j);
					//funcB(i, j);
					//funcC(i, j);
				}
			}
		}
	}
	
	cout << B << " " << A << endl;
	return 0;
}
