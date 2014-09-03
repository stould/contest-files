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

int N, M, K, Q;
char S[105];

string simul(int K, int M) {
	string ans = string(S);

	int pos = 0, next = -1;

	if (M >= N) {
		M = (M % (2 * N));
	}

	for (int i = 0; i < M; i++) {
		if (ans[pos] == 'o') {
			ans[pos] = 'x';
		} else {
			ans[pos] = 'o';
		}
		pos = (pos + K) % N;
	}
	return ans;
}

int main(void) {
	for ( ; scanf("%d%d", &N, &Q) == 2 && N + Q != 0; ) {
		scanf("%s", S);
		for (int i = 0; i < Q; i++) {
			scanf("%d%d", &K, &M);
			printf("%s\n", simul(K, M).c_str());
		}
	}
    return 0;
}
