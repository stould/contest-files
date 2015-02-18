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

const int MAXN = 1000005;

int N;
string S;
Int A, B;

Int L[MAXN], R[MAXN];

int main(void) {
	cin >> S >> A >> B;

	N = (int) S.size();

	for (int i = 0; i < N; i++) {
		Int p = S[i] - '0';

		if (i == 0) {
			L[i] = p % A;
		} else {
			L[i] = (L[i - 1] * 10 + p) % A;
		}
		L[i] = (L[i] + A) % A;
	}

	Int pow = 1;

	for (int i = N - 1; i >= 0; i--) {
		Int p = S[i] - '0';
		
		if (i < N - 1) {
			R[i] = (p * pow + R[i + 1]) % B;
		} else {
			R[i] = p;
		}
		
		R[i] = (R[i] + B) % B;
		pow = (pow * 10LL) % B;

		if (i > 0 && S[i] != '0') {
			if (R[i] == 0 && L[i - 1] == 0) {
				cout << "YES\n" << S.substr(0, i) << "\n" << S.substr(i, S.size() - i) << "\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
    return 0;
}
