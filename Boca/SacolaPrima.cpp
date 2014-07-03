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

const int MAX_P = 500001;

int N, P;
bool b[MAX_P];
vector<int> primes;

void build(void) {
	memset(b, true, sizeof(b));

	for (int i = 2; i < sqrt(MAX_P); i++) {
		if (b[i]) {
			for (int j = i * i; j < MAX_P; j += i) {
				b[j] = false;
			}
		}
	}
	for (int i = 2; i < MAX_P; i++) {
		if (b[i]) {
			primes.push_back(i);
		}
	}
}

int main(void) {
	build();
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		int ans = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &P);
			if (binary_search(primes.begin(), primes.end(), P)) {
				ans += 1;
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}
