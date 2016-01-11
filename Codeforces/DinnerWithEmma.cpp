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

const int MAXN = 105;

int N, M;
int P[MAXN][MAXN], M_VAL[MAXN];

int main(void) {
	cin >> N >> M;

	fill(M_VAL, M_VAL + MAXN, INT_MAX);

	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> P[i][j];

			chmin(M_VAL[i], P[i][j]);
		}
		chmax(ans, M_VAL[i]);
	}

	cout << ans << "\n";
	return 0;
}
