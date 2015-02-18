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

int N, M;
char ch[110][110];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main(void) {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", ch[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (ch[i][j] != '.') continue;
			if ((i + j) % 2 == 0) {
				ch[i][j] = 'W';
			} else {
				ch[i][j] = 'B';
			}
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%s\n", ch[i]);
	}
    return 0;
}
