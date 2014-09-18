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

const int MAXN = 100005;

int N, X;
Int P[MAXN];

int main(void) {
	cin >> N >> X;

	X -= 1;

	int pz = -1;
	int m = INT_MAX, m_pos = -1;

	for (int i = 0; i < N; i++) {
		cin >> P[i];

		if (P[i] < m) {
			m = P[i];
			m_pos = i;
		}

	}

	for (int i = 0; i < N; i++) {
		P[i] -= m;
	}		

	for (int i = 0; i < N; i++) {
		if (P[i] == 0) {
			int ps = i;

			while () {
				P[i] += 1;
				P[ps] -= 1;
				ps = (ps + 1) % N;
			}
			break;
		}
	}		

	for (int i = 0; i < N; i++) {
		cout << P[i] << " ";
	}
	cout << "\n";
	
    return 0;
}
