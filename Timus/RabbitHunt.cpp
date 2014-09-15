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

const double EPS = 1e-7;

int N;
pair<double, double> P[220];

int main(void) {
	for ( ; scanf("%d", &N) == 1 && N > 0; ) {
		for (int i = 0; i < N; i++) {
			scanf("%lf%lf", &P[i].first, &P[i].second);
		}

		int ans = 0;
		
		for (int i = 0; i < N; i++) {
			int hor = 1, ver = 1;
			map<double, int> cnt;

			for (int j = i + 1; j < N; j++) {
				double curr = (P[i].second - P[j].second) / (double) (P[i].first - P[j].first);
				bool done = false;
				if (P[i].first == P[j].first) {
					hor += 1;
					done = true;
				} 
				if (P[i].second == P[j].second) {
					ver += 1;
					done = true;
				}
				if (!done) {				
					cnt[curr] += 1;
					chmax(ans, cnt[curr] + 1);
				}	 
			}
			chmax(ans, hor);
			chmax(ans, ver);
		}
		printf("%d\n", ans);
	}	
    return 0;
}
