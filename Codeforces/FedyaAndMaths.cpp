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

string S;
int B[5], C[5], D[5];

int main(void) {
	B[0] = 2; C[0] = 3;	D[0] = 4;
	B[1] = 4; C[1] = 4;	D[1] = 1;
	B[2] = 3; C[2] = 2;	D[2] = 4;
	B[3] = 1; C[3] = 1;	D[3] = 1;

	cin >> S;

	int pos = 0;

	for (int i = 0; i < (int) S.size(); i++) {
		pos = (((pos * 10) % 4) + (S[i] - '0')) % 4;
	}

	pos = (((pos - 1) % 4) + 4) % 4;

	if (S == "0") {
		printf("%d\n", (4) % 5);
	} else { 
		
		int ans = (1 + B[pos] + C[pos] + D[pos]) % 5;
		
		printf("%d\n", ans);
	}
    return 0;
}
