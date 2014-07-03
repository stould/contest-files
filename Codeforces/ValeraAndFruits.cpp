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

const int MAXN = 3030;

int N, V;
int P[MAXN];

int main(void) {
	scanf("%d%d", &N, &V);
	for (int i = 0; i < N; i++) {
		int A, B;
		scanf("%d%d", &A, &B);
		P[A] += B;
	}

	int ans = 0;
	
	for (int i = 1; i < MAXN; i++) {	 
		int us = 0;
		if (us + P[i - 1] < V) {
			us += P[i - 1];
			P[i - 1] = 0;
		} else if (us + P[i - 1] >= V) {
			us = V;
			ans += us;
			continue;
		}
		if (us + P[i] < V) {
			us += P[i];
			P[i] = 0;
		} else if (us + P[i] >= V) {
			P[i] -= (V - us);
			us = V;
		}
		ans += us;
	}

	printf("%d\n", ans);
	
    return 0;
}
