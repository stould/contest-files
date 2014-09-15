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

int N, M, A, K;
string S;

int main(void) {
	cin >> N >> M >> A >> K >> S;
	bool ok = true;

	if (S.size() < N) {
		ok = false;
	} else {
		for (int i = 0; i < (int) S.size(); i++) {
			if (S[i] >= '0' && S[i] <= '9') {
				K -= 1;
			} else if (S[i] >= 'a' && S[i] <= 'z') {
				M -= 1;
			} else if (S[i] >= 'A' && S[i] <= 'Z') {
				A -= 1;
			}
		}
		if (A > 0 || K > 0 || M > 0) {
			ok = false;
		}
	}
	if (ok) {
		cout << "Ok =/\n";
	} else {
		cout << "Ufa :)\n";
	}

    return 0;
}
