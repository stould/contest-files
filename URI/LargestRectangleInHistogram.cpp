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
int P[MAXN], L[MAXN], R[MAXN];

void build(void) {
	stack<int> sL, sR;
	
	sL.push(0);
	sR.push(N + 1);

	for (int i = 1; i <= N; i++) {
		while (P[sL.top()] >= P[i]) {
			sL.pop();
		}
		L[i] = sL.top() + 1;
		sL.push(i);
	}
	for (int i = N; i >= 1; i--) {
		while (P[sR.top()] >= P[i]) {
			R[i] = sR.top();
			sR.pop();
		}
		R[i] = sR.top() - 1;
		sR.push(i);		
	}
}

int main(void) {
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		stack<int> s;

		Int ans = 0LL;
		
		P[0] = P[N + 1] = -1;
		
		for (int i = 1; i <= N; i++) {
			scanf("%d", &P[i]);
		}
		
		build();
		
		for (int i = 1; i <= N; i++) {
			//			printf("%d - %d %d\n", i, L[i], R[i]);
			chmax(ans, (R[i] - L[i] + 1) * (Int) P[i]);
		}

		printf("%lld\n", ans);
	}
    return 0;
}
