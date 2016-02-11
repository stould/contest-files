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

const int MAXN = 500005;

int N;
pair<int, int> P[MAXN];
int dp[MAXN];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	return a.first < b.first;	
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i].first >> P[i].second;
	}

	sort(P, P + N, cmp);

	dp[0] = 1;
	
	for (int i = 1; i < N; i++) {
		int l = 0, h = i - 1, m;
		int best = -1;

		dp[i] = dp[i -1];
		
		while (l <= h) {
			m = (l + h) / 2;

			if (P[m].second < P[i].first) {
				best = max(best, m);
				l = m + 1;
			} else {
				h = m - 1;
			}
		}

		if (best != -1) {
			chmax(dp[i], dp[best] + 1);
		}
	}
	
	cout << dp[N - 1] << "\n";
	
	return 0;
}
