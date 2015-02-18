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

int main(void) {
	cin >> N;

	if (N < 4) {
		puts("NO");
	} else {
		puts("YES");
		if (N == 4) {
			printf("2 * 1 = 2\n");
			printf("2 * 3 = 6\n");
			printf("6 * 4 = 24\n");		
		} else if (N == 5) {
			printf("4 * 5 = 20\n");
			printf("3 - 1 = 2\n");
			printf("2 * 2 = 4\n");
			printf("20 + 4 = 24\n");
		} else {
			printf("4 * 6 = 24\n");
			printf("1 + 2 = 3\n");
			printf("3 - 3 = 0\n");
			
			for (int i = 5; i <= N; i++) {
				if (i == 6) {
					continue;
				}
				printf("%d * %d = 0\n", i, 0);			
			}
			
			printf("24 + 0 = 24\n");
		}
	}
    return 0;
}
