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

const Int INF = 1000101010010101001LL;
Int N;

//2^a * 3^b
Int func(int a) {
	Int s = (Int) pow(3.0, a);
	
	for (int i = 0; i <= 31; i++) {
		Int now = s * (Int) pow(2.0, i);

		if (now >= N) {
			return now;
		}
	}

	return -1;
}

int main(void) {
	for ( ; cin >> N && N != 0; ) {
		int l = 0, h = 19, m;
		Int curr = INF;

		for (int x = 0; x <= 19; x++) {
			Int prox = func(x);
			curr = min(curr, prox);
		}

		cout << curr << "\n";
	}
    return 0;
}
