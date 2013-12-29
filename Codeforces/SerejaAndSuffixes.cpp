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

const int MAXN = 100005;

int N, M;

int a[MAXN];
int d[MAXN];

int main(void) {
	N = in();
	M = in();

	int i;

	for (i = 0; i < N; i++) {
		a[i] = in();
	}

	set<int> s;
	s.insert(a[N-1]);
	d[N-1] = 1;


	for (i = N - 2; i >= 0; i--) {
		int c = (int) s.size();

		s.insert(a[i]);

		d[i] = d[i + 1];

		if (c != (int) s.size()) {
			d[i] += 1;
		}		
	}

	for (i = 0; i < M; i++) {
		int curr = in();

		printf("%d\n", d[curr - 1]);
	}
    return 0;
}
