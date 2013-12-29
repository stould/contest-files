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

int K;

string st[10];

int cnt[15] = {0};

int main(void) {
	K = in();

	int i;
	int j;

	for (i = 0; i < 4; i++) {
		cin >> st[i];

		for (j = 0; j < 4; j++) if (st[i][j] != '.') {
			cnt[st[i][j] - '0'] += 1;
		}
	}

	bool ok = true;

	for (i = 1; i < 10; i++) {
		if (cnt[i] > 2 * K) {
			ok = false;
		}
	}

	if (ok) {
		puts("YES");
	} else {
		puts("NO");
	}

    return 0;
}
