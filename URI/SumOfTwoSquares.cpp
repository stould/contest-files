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
set<int> s;

int main(void) {
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			int sum = i * i + j * j;
			if (sum > 10000) {
				break;
			}
			s.insert(sum);
		}
	}
	for ( ; scanf("%d", &N) == 1; ) {
		if (s.count(N)) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
    return 0;
}
