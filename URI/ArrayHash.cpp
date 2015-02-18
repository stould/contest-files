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

int T;
int L;
char S[60];

int main(void) {
	scanf("%d", &T);

	for ( ; T--; ) {
		scanf("%d", &L);

		int ans = 0;

		for (int i = 0; i < L; i++) {
			scanf("%s", S);

			int N = strlen(S);
			
			for (int j = 0; j < N; j++) {
				ans += (S[j] - 'A') + i + j;
			}
		}
		
		printf("%d\n", ans);
	}
    return 0;
}
