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

const double PI = acos(-1.0);
int N, D, P;

int main(void) {
	int t = 1;
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		double low = 1010101010.0;
		int dd = -1;
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &D, &P);
			double curr_cost = P / (D * D * PI);

			if (curr_cost < low) {
				low = curr_cost;
				dd = D;
			}
		}
		printf("Menu %d: %d\n", t++, dd);
	}
    return 0;
}
