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

int F[3];
int J[700];

int main(void) {
	int ans = 0;

	memset(J, 0, sizeof(J));
	for (int i = 0; i < 3; i++) {
		F[i] = in();

		for (int j = F[i]; j < F[i] + 200; j++) {
			J[j] = 1;
		}
	}
	
	for (int i = 0; i < 600; i++) {
		if (J[i] == 0) {
			ans += 100;
		}
	}
	printf("%d\n", ans);
    return 0;
}
