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

int N, M, A, B;
string S[110], SS[110];

int main(void) {
	for ( ; cin >> N >> M && N + M != 0; ) {
		for (int i = 0; i < N; i++) {
			cin >> S[i];
		}
		cin >> A >> B;

		for (int i = 0; i < N; i++) {
			SS[i] = "";
			for (int j = 0; j < M; j++) {
				for (int k = 0; k < B / M; k++) {
					SS[i] += S[i][j];
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < A / N; j++) {
				cout << SS[i] << "\n";
			}
		}
		cout << "\n";
	}

    return 0;
}
