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

int T;
string A, B;
int sP[26], sC[26];

bool func(void) {
	for (int i = 0; i < 26; i++) {
		if (sP[i] != sC[i]) {
			return false;
		}
	}
	return true;
}

int main(void) {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> A >> B;

		for (int i = 0; i < 26; i++) {
			sP[i] = sC[i] = 0;
		}

		int N = (int) A.size();
		int M = (int) B.size();
		
		for (int i = 0; i < M; i++) {
			sC[A[i] - 'a'] += 1;
			sP[B[i] - 'a'] += 1;
		}

		bool ok = func();

		if (!ok) {
			for (int i = M; i < N; i++) {
				if (func()) {
					ok = true;
					break;
				} 
				sC[A[i] - 'a'] += 1;
				sC[A[i - M] - 'a'] -= 1;
			}
		}
		if (func()) {
			ok = true;
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
    return 0;
}
