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

int A[5];
int B[5];
int C[5];
int D[5];

int main(void) {
	N = in();

	int i;

	bool ok = false;

	int id = -1;
	int ansA = 0;
	int ansB = 0;

	for (i = 0; i < 4; i++) {
		A[i] = in();
		B[i] = in();
		C[i] = in();
		D[i] = in();

		if (!ok && min(A[i], B[i]) + min(C[i], D[i]) <= N) {
			ok = true;
			ansA = min(A[i], B[i]);
			ansB = N - ansA;
			id = i + 1;
		}
	}

	if (!ok) {
		puts("-1");
	} else {
		printf("%d %d %d\n", id, ansA, ansB);
	}
	
    return 0;
}
