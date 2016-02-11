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

int N, M;
pair<int, pair<int, int> > P[MAXN];
int dp[MAXN];

int main(void) {
	while (cin >> N >> M) {
		for (int i = 0; i < M; i++) {
			cin >> P[i].first >> P[i].second.first >> P[i].second.second;
		}

		sort(P, P + M);

		for (int i = 0; i < N; i++) {

		}
	}
	return 0;
}
