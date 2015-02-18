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

int N;
string S[MAXN];
int P[MAXN];

int main(void) {
	for ( ; cin >> N && N != 0; ) {
		memset(P, 0, sizeof(P));

		for (int i = 0; i < N; i++) {
			cin >> S[i];
			for (int j = 0; j < (int) S[i].size(); j++) {
				P[i] += (int) S[i][j];
			}
		}

		bool ok = false;
		int l = 0, h = N, m;

		for (int x = 0; x < 50; x++) {
			m = (l + h) / 2;
			Int A = 0LL;
			Int B = 0LL;

			for (int j = m, cnt = 1; j >= 0; j--, cnt++) {
				A += cnt * (Int) P[j];
			}
			for (int j = m + 1, cnt = 1; j < N; j++, cnt++) {
				B += cnt * (Int) P[j];
			}
			if (A == B) {
				ok = true;
				cout << S[m] << "\n";
				break; 
			} else if (A < B) {
				l = m;
			} else {
				h = m;
			}	
		}
		if (!ok) {
			cout << "Impossibilidade de empate.\n";
		}
	}

    return 0;
}
