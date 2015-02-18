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

int N;
int X[MAXN];

int main(void) {
	N = in();

	int P = 1;
	vector<int> ans;

	for (int i = 0; i < N; i++) {
		X[i] = in();

		if (X[i] == P) {
			ans.push_back(2000 + i + 1);
			P += 1;
		}
	}

	printf("%d\n", (int) ans.size());

	for (int i = 0; i < (int) ans.size(); i++) {
		printf("%d ", ans[i]);
	}

	puts("");

    return 0;
}
