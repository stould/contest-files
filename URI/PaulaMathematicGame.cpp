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
char b[3];
int main(void) {
	scanf("%d", &N);
	for ( ; N--; ) {
		scanf("%s", b);

		if (b[0] == b[2]) {
			printf("%d\n", (b[0] - '0') * (b[2] - '0'));
		} else {
			if (isupper(b[1])) {
				printf("%d\n", (b[2] - '0') - (b[0] - '0'));
			} else {
				printf("%d\n", (b[0] - '0') + (b[2] - '0'));
			}
		}
	}
    return 0;
}
