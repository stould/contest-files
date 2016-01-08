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
int in() { int x; int p = scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 100005;

int N;
int P[MAXN];

int main(void) {
	N = in();
	for (int i = 0; i < N; i++) {
		P[i] = in();
	}
	int ans = -1, gap = 0;
	
	for (int i = 0; i < N - 1; i++) {
		int now = 0, old = 0;
		if (i > 0) {
			old += max(0, P[i] - P[i - 1]);
		}
		old += max(0, P[i + 1] - P[i]);

		if (i + 2 < N) {			
			old += max(0, P[i + 2] - P[i + 1]);
		}
		swap(P[i], P[i + 1]);
		if (i > 0) {
			now += max(0, P[i] - P[i - 1]);
		}
		now += max(0, P[i + 1] - P[i]);

		if (i + 2 < N) {			
			now += max(0, P[i + 2] - P[i + 1]);
		}
		swap(P[i], P[i + 1]);
		if (old - now > gap) {
			gap = old - now;
			ans = i + 1;
		}
	}
	
	cout << ans << endl;

    return 0;
}
