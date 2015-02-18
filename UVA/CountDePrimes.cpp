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

const int MAXN = 5000005;
int A, B;
bool p[MAXN];
int sum[MAXN], q[MAXN];

void build(void) {
	memset(p, true, sizeof(p));

	for (int i = 2; i < MAXN; i++) {
		if (p[i]) {
			for (int j = i + i; j < MAXN; j += i) {
				sum[j] += i;
				p[j] = false;
			}
		}
		if (p[sum[i]]) {
			q[i] += 1;
		}
		q[i] += q[i - 1];
	}
}

int main(void) {
	build();
	for ( ; scanf("%d%d", &A, &B) == 2; ) {
		printf("%d\n", q[B] - q[A - 1]);
	}
	
    return 0;
}
