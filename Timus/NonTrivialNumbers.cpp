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

const int MAXN = 1000005;
const int EPS = 1e-8;

int dsum[MAXN];
bool p[MAXN];

void build(void) {
	for (int i = 0; i < MAXN; i++) {
		dsum[i] = 1;
	}
	dsum[0] = 0;
	
	for (int i = 2; i <= MAXN / 2; i++) {		
		for (int j = i; j < MAXN; j += i) {
			dsum[j] += i;
		}		
	}
}

int main(void) {
	build();
	int A, B;
	scanf("%d%d", &A, &B);
	double cost = 101010101010;
	int id = -1;
	for (int i = A; i <= B; i++) {
		double ac = ((double) dsum[i] / (double) i);
		if (i == 1) ac = 0.0;
		if (ac < cost) {
			cost = ac;
			id = i;
		}
	}
	printf("%d\n", id);
    return 0;
}
