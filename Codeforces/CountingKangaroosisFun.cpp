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

int N;
vector<int> K;

int main(void) {
	N = in();

	K.resize(N);

	int i;
	int ans = N;

	for (i = 0; i < N; i++) {
		K[i] = in();		
	}

	sort(K.begin(), K.end());

	int l = 0, h = N / 2;

	for ( ; l < N / 2 && h < N; ) {
		if (2 * K[l] <= K[h]) {
			l += 1;
			h += 1;
			ans -= 1;
		} else {
			h += 1;
		}

	}


	printf("%d\n", ans);

    return 0;
}
