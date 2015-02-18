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
int P[20];
bool prime[50];

int func(int pos, int mask) {
	if (pos == N) {
		if (prime[P[pos - 1] + P[0]]) {
			for (int i = 0; i < N; i++) {
				if (i > 0) printf(" ");
				printf("%d", P[i]);
			}
			printf("\n");
		}
	} else {
		for (int i = 2; i <= N; i++) {
			if (!(mask & (1 << i))) {
				if (prime[i + P[pos - 1]]) {
					P[pos] = i;
					func(pos + 1, mask | (1 << i));				
				}
			}
		}		
	}
}

bool isPrime(int x) {
	if (x == 2 || x == 3) {
		return true;
	} else if (x % 2 == 0) {
		return false;
	} else {
		for (int i = 3; i <= (int) sqrt(x); i++) {
			if (x % i == 0) return false;
		}
		return true;
	}
}

int main(void) {
	for (int i = 2; i <= 50; i++) {
		prime[i] = isPrime(i);
	}
	int test = 1;
	for ( ; scanf("%d", &N) == 1; ) {
		if (test > 1) printf("\n");
		P[0] = 1;
		printf("Case %d:\n", test++);
		if (N % 2 == 0 && N > 0 && N <= 16) {
			func(1, 1 << 1);
		}
	}
    return 0;
}
