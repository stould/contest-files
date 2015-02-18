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

int N, M;

int main(void) {
	for ( ; scanf("%d%d", &N, &M) && !(N + M == 0); ) {
		int C, ans = 0;
		set<int> st;
		
		for (int i = 0; i < N; i++) {
			scanf("%d", &C);
			st.insert(C);
		}
		
		for (int i = 0; i < M; i++) {
			scanf("%d", &C);
			if (st.count(C)) {
				ans += 1;
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}
