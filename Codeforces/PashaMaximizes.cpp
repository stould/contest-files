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
int K;

int main(void) {
	cin >> S >> K;
	int N = (int) S.size();
	int changes = 0;

	for (int i = 0; i < N && changes < K; i++) {
		bool ok = false;
		for (int j = 9; !ok && j >= 1; j--) {
			if (S[i] >= char('0' + j)) continue;
			for (int k = i + 1; !ok && k < N && changes + (k - i) <= K; k++) {
				if (S[k] == char('0' + j)) {
					ok = true;
					changes += (k - i);
					while (k > i) {
						swap(S[k], S[k - 1]);
						k--;
					}
					break;
				}
			}
		}
	}

	cout << S << "\n";

    return 0;
}
