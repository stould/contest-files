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

int N, K;
int P[MAXN];

int main(void) {
	for ( ; scanf("%d%d", &N, &K) == 2 && N + K != 0; ) {
		int pos = 0, zero = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);			
			if (P[i] > 0) {
				pos += 1;
			} else if (P[i] == 0) {
				zero += 1;
			}
		}
		sort(P, P + N);
		int used = 0;
		vector<int> ans;

		for (int i = N - 1; i >= 0; i--) {
			
		}
		
		sort(ans.begin(), ans.end());

		for (int i = 0; i < K; i++) {
			if (i) printf(" ");
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
    return 0;
}
