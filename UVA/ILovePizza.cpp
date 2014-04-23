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

const int MAXS = 610;

int N, L;
char buff[MAXS];

int C[30];

char pos[] = "MARGIT";
int cnt[6] = {1, 3, 2, 1, 1, 1};

int main(void) {
	scanf("%d", &N);

	for ( ; N--; ) {
		scanf("%s", buff);

		L = strlen(buff);

		int ans = 1000000;
		
		memset(C, 0, sizeof(C));

		for (int i = 0; i < L; i++) {
			C[buff[i] - 'A'] += 1;
		}

		for (int i = 0; i < 6; i++) {
			ans = min(ans, C[pos[i] - 'A'] /  cnt[i]);
		}
		printf("%d\n", ans);
	}
    return 0;
}
