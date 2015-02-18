#include <cstdio>
#include <cstring>
#include <algorithm>

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

int N;

struct data {
	int a, c, h;

	data(){}
	data(int a, int c, int h): a(a), c(c), h(h){}
	
	bool operator<(const data& other) const {
		return a < other.a;
	}
};

data P[410];
int dp[40005];

int main(void) {
	scanf("%d", &N);

	int best = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &P[i].h, &P[i].a, &P[i].c);
		chmax(best, P[i].a);
	}

	sort(P, P + N);

	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < P[i].c; j++) {
			for (int k = P[i].a; k >= P[i].h; k--) {
				dp[k] |= dp[k - P[i].h];
			}
		}
	}
	for (int i = best; i >= 0; i--) {
		if (dp[i]) {
			printf("%d\n", i);
			break;
		}
	}
    return 0;
}
