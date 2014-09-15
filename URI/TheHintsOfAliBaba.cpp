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

int N, K;

int main(void) {
	for ( ; scanf("%d%d", &N, &K) == 2; ) {
		int P;
		map<int, bool> appear;
		vector<int> vs;
		for (int i = 0; i < N; i++) {
			scanf("%d", &P);
			if (!appear[P]) {
				vs.push_back(P);
				appear[P] = true;
			}
		}
		for (int i = 0; i < (int) vs.size(); i++) {
			if (i > 0) printf(" ");
			printf("%d", vs[i]);
		}
		printf("\n");
	}
    return 0;
}
