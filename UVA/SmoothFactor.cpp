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

const int MAXN = 100005;

int N;
int P[MAXN], Q[MAXN];

int main(void) {
	for ( ; cin >> N; ) {
		
		for (int i = 0; i < N; i++) {
			cin >> P[i];
			Q[i] = 0;

			if (i > 0 && P[i - 1] > P[i]) {
				Q[i] = 1;
			}
		} 

		int last = 0, cnt = 0, len = 0;
		int ans = 0;

		for (int i = 0; i < N; i++) {
			if (Q[i]) {
				cnt += 1;
				
				if (cnt > 1) {
					cnt = 1;
					len = i - last + 1;
				} else {
					len += 1;
				}				
				last = i;
			} else {
				len += 1;
			}

			chmax(ans, len);
		}
		printf("%d\n", ans);
	}
    return 0;
}
