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

const int MAXN = 300005;

int N;
Int P[MAXN], S[MAXN], X[MAXN], SP[MAXN];

void func(int l, int r) {
	if (l == r) {
		SP[l] += 1;
		return;;
	}
	else {
		int m = (l + r - 1) / 2;
		for (int i = l; i <= r; i++) {
			SP[i] += 1;
		}
		func(l, m);
		func(m + 1, r);
	}
}

int main(void) {
	cin >> N;
	Int ans = 0LL;

	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}

	sort(P + 1, P + 1 + N);

	for (int i = 1; i <= N; i++) {
		S[i] = S[i - 1] + P[i];
		if (i != N) {
			ans += P[i];
		}
	}
	for (int i = 1; i <= N + 1; i++) {
		ans += S[N] - S[i];
	}

	cout << ans << endl;
	
    return 0;
}
