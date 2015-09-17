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

const int MAXN = 3003;
const int INF = INT_MAX / 3;

int N;
pair<int, int> P[MAXN];

int main(void) {
	while (cin >> N) {
		for (int i = 0; i < N; i++) {
			cin >> P[i].first >> P[i].second;
		}
		sort(P, P + N);

		int ans = 0;

		for (int i = 0; i < N; i++) {
			if (i + 1 < N) {
				int l = -INF;
				int h = +INF;

				if (P[i + 1].second >= P[i].second) {
					h = P[i + 1].second;
				} else {
					l = P[i + 1].second;
				}
				
				ans += 1;
					
				for (int j = i + 2; j < N; j++) {
					if (P[j].second >= P[i].second) {
						if (P[j].second <= h) {
							ans += 1;
						}
						h = min(h, P[j].second);
					} else {
						if (P[j].second >= l) {
							ans += 1;
						}
						l = max(l, P[j].second);
					}
				}
			}		
		}
		
		cout << ans << endl;
	}
	return 0;
}
