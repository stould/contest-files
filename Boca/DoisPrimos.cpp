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

const int MAX_P = 10000005;
int N;
bool b[MAX_P];
vector<int> primes;

void build(void) {
	memset(b, true, sizeof(b));

	for (int i = 2; i < sqrt(MAX_P); i++) {
		if (b[i]) {
			for (int j = i * i; j > 0 && j < MAX_P; j += i) {
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
	bool ok = false;
	for ( ; cin >> N && N != 0; ) {
		vector<int> ans;

		for (int i = 0; i < (int) primes.size(); i++) {
			if (N % primes[i] == 0) {
				ans.push_back(primes[i]);
				while (N % primes[i] == 0) {
					N /= primes[i];
				}
				if (N == 1) {
					ans.push_back(ans[0]);
				} else {
					ans.push_back(N);
				}
				sort(ans.begin(), ans.end());
				break;
			}
		}
		printf("%d %d", ans[0], ans[1]);
	}
    return 0;
}
