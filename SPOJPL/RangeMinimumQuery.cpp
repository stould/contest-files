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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 100005;

int N, Q;
int P[MAXN];
int dp[MAXN][19];

void build() {
	int pw = 1; //2^pw
	int base = 2;

	for (int i = 0; i < N; i++) {
		dp[i][0] = P[i];
	}
  
	while (base <= N) {
		for (int i = 0; i + base / 2 - 1 < N; i++) {
			int before = base / 2;		
			dp[i][pw] = min(dp[i][pw - 1], dp[i + before][pw - 1]);
		}    
		pw += 1;
		base *= 2;
	}
}

int query(int l, int r) {
	int len = r - l + 1;

	if (len == 1) return dp[l][0];
  
	int ps = 1;
	int pw = 0;
	
	while (l + 2 * ps <= r) {
		ps *= 2;
		pw += 1;
	}

	int a = dp[l][pw];
	int b = dp[r - ps + 1][pw];

	return min(a, b);
}

int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &P[i]);
	}

	build();

	cin >> Q;

	for ( ; Q--; ) {
		int A, B;

		scanf("%d%d", &A, &B);
		printf("%d\n", query(A, B));
	}
	return 0;
}
