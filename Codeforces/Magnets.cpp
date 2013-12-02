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

int N;

char S[100005][5];

int main(void) {
	N = in();

	int i;

	for (i = 0; i < N; i++) scanf("%s", S[i]);

	int ans = 1;

	for (i = 1; i < N; i++) {
		if (strcmp(S[i], S[i - 1]) != 0) {
			ans += 1;
		}
	}

	printf("%d\n", ans);

    return 0;
}