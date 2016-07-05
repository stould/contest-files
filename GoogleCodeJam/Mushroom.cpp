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

const int MAXN = 1010;

int T, N;
int P[MAXN];

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		int A = 0;
		int B = 0;
		double rate = 0;
		
		for (int i = 0; i < N; i++) {
			cin >> P[i];			

			if (i > 0) {
				if (P[i - 1] > P[i]) {
					A += P[i - 1] - P[i];
				}
				chmax(rate, (P[i - 1] - P[i]) / 10.0);
			}			
		}

		for (int i = 1; i < N; i++) {
			B += min(P[i - 1], (int) (rate * 10.0));							
		}

		cout << "Case #" << t << ": " << A << " " << B << endl;
	}
	
    return 0;
}
