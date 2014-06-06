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

int F, R;

int main(void) {
	scanf("%d%d", &F, &R);
	vector<int> vp(R + 2);

	vp[0] = 1;
	vp[R + 1] = F;

	for (int i = 1; i <= R; i++) {
		scanf("%d", &vp[i]);
	}
	int l = max(vp[1] - vp[0], vp[R + 1] - vp[R]);
	for (int i = 2; i < (int) vp.size() - 1; i++) {
		l = max(l, (vp[i] - vp[i - 1]) / 2);
	}
	printf("%d\n", l);
    return 0;
}
