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

int P, S, N;
int T[3], D[2];
int pos[15];
bool play[15];

int main(void) {
	for ( ; cin >> P >> S && P + S != 0; ) {
		for (int i = 0; i < 3; i++) {
			cin >> T[i];
		}
		for (int i = 0; i < P; i++) {
			pos[i] = 0;
			play[i] = true;
		}

		cin >> N;

		int id = 0;
		bool ok = false;
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &D[0], &D[1]);

			if (!play[id]) {
				while (!play[id]) {
					play[id] = true;
					id = (id + 1) % P;
				}
			}
			int curr = pos[id] + D[0] + D[1];			

			if (!ok && curr > S) {
				cout << (id + 1) << "\n";
				ok = true;
			}

			if (curr == T[0] || curr == T[1] || curr == T[2]) {
				play[id] = false;
			}
			pos[id] = curr;
			id = (id + 1) % P;
		}
	}
    return 0;
}
