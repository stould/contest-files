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

int N;
string P[110];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	bool ok = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int s = 0;
			for (int k = 0; k < 4; k++) {
				int pi = i + dx[k];
				int pj = j + dy[k];

				if (pi >= 0 && pj >= 0 && pi < N && pj < N && P[pi][pj] == 'o') {
					s += 1;
				}
			}
			if (s % 2 != 0) ok = false;
		}
	}
	if (ok) cout << "YES";
	else cout << "NO";
    return 0;
}
