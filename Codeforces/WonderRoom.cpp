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

const Int INF = 100101010010100000LL;

Int N, A, B;

int main(void) {
	cin >> N >> A >> B;

	Int S = 6LL * N;
	Int ans = INF;
	
	Int ansA = -1;
	Int ansB = -1;

	for (int i = 1; i <= 100000; i++) {
		Int sa = max(A, (Int) i);
		Int sb = max(B, (Int) (S / i));
		
		if (sa * sb >= S && sa * sb < ans) {
			ans = sa * sb;
			ansA = sa;
			ansB = sb;		
		}
	}

	cout << ans << "\n" << ansA << " " << ansB << "\n";

    return 0;
}
