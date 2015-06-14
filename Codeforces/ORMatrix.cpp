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

const int MAXN = 110;

int N, M;
int O[MAXN][MAXN], R[MAXN][MAXN];

bool ok() {
	int tmp[MAXN][MAXN];

	memset(tmp, 0, sizeof(tmp));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				tmp[i][j] |= R[k][j];
			}
			for (int k = 0; k < M; k++) {
				tmp[i][j] |= R[i][k];
			}
			if (O[i][j] != tmp[i][j]) {
				return false;
			}
		}
	}
	
	return true;
}

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> O[i][j];
			R[i][j] = 1;
		}
	}
	
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (O[i][j] == 0) {
				for (int k = 0; k < N; k++) {
					R[k][j] = 0;
				}
				for (int k = 0; k < M; k++) {
					R[i][k] = 0;
				}
			}
		}
	}

	if (ok()) {
		cout << "YES\n";

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << R[i][j] << " ";
			}
			cout << "\n";
		}			
	} else {
		cout << "NO\n";
	}
	
	return 0;
}
