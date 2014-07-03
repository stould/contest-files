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

vector<int> C(5), D(5), P(5);

int main(void) {	
	for (int i = 0; i < 5; i++) {
		cin >> P[i];
		C[i] = D[i] = P[i];
	}
	sort(C.begin(), C.end());
	sort(D.begin(), D.end()); reverse(D.begin(), D.end());

	char ans;

	if (P == C) {
		ans = 'C';
	} else if (P == D) {
		ans = 'D';
	} else {
		ans = 'N';
	}
	cout << ans << "\n";
    return 0;
}
