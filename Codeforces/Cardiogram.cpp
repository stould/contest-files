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
const int INF = INT_MAX / 3;
int N;
int P[MAXN];
string M[3 * MAXN];

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &P[i]);
	}

	for (int i = 0; i < 3 * MAXN; i++) {
		M[i] = string(3 * MAXN, '.');
	}

	int px = 3 * MAXN / 2, py = 3 * MAXN / 2;
	int min_x = INF, max_x = -INF;
	
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < P[i]; j++) {
				M[px][py] = '/';
				px -= 1;
				py += 1;
				min_x = min(min_x, px);
				max_x = max(max_x, px);
			}
		} else {
			for (int j = 0; j < P[i]; j++) {
				M[px][py] = '\\';
				px += 1;
				py += 1;
				min_x = min(min_x, px);
				max_x = max(max_x, px);
			}
		}
		px += 1;
	}
	for (int i = min_x + 1; i < c max_x; i++) {
		cout << M[i].substr(3 * MAXN / 2, 13) << "\n";
	}
    return 0;
}
