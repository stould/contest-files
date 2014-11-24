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

const int MAXN = 5005;

int N, K;
int P[MAXN], Q[MAXN];

int main(void) {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
		Q[i] = P[i];
	}

	sort(P, P + N);

	int s = K + 1;

	for (int i = 0; i < N; i++) {
		for (int j = s; j < 
		
		if (i > 0 && i % K == 0) {
			s += 1;
		}
	}

    return 0;
}
