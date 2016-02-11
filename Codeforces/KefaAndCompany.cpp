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

int N;
Int D;
pair<Int, Int> P[MAXN];
Int S[MAXN], Q[MAXN];

int main(void) {
	cin >> N >> D;

	for (int i = 0; i < N; i++) {
		cin >> P[i].first >> P[i].second;
	}

	sort(P, P + N);

	Q[0] = P[0].second;
	
	for (int i = 1; i < N; i++) {
		Q[i] = Q[i - 1] + P[i].second;
	}

	Int ans = 1;
	
	for (int i = 0; i < N; i++) {
		int l = i, h = N - 1, m;

		while (l <= h) {
			m = (l + h) / 2;

			Int quality = Q[m];
			
			if (i > 0) {
				quality -= Q[i - 1];
			}
			
			bool can = (P[m].first - P[i].first) < D;
			
			if (can) {
				chmax(ans, quality);
				l = m + 1;
			} else {
				h = m - 1;
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
