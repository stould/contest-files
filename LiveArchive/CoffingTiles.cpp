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

const int MAX = 1000000;

int sum[MAX + 10];
int P[MAX + 10];

int main(void) {
	for (int i = 1; i <= (int) sqrt(MAX); i++) {
		for (int j = i; j <= MAX; j += i) {
			if (j >= i * i) {
				sum[j] += 1;			
			}
		}
	}
	
	memset(P, 63, sizeof(P));
	
	for (int i = 1; i <= MAX; i++) {
		P[sum[i]] = min(P[sum[i]], i);
	}
	
	int T, N;

	cin >> T;

	for ( ; T--; ) {
		cin >> N;
		if (P[N] == 1061109567) {
			cout << "Too big\n";
		} else {
			cout << P[N] << "\n";
		}
	}
    return 0;
}
