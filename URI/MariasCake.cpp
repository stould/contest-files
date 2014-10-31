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

const int MAXN = 110;
const int INF = INT_MAX / 3;

int T, D, I, B;
int P[MAXN], Qi[MAXN];
int C[MAXN][MAXN][2];
Int whole_cost[MAXN];

int main(void) {
	cin >> T;
	
	for ( ; T--; ) {
		cin >> D >> I >> B;
		
		for (int i = 0; i < I; i++) {
			cin >> P[i];
		}
		
		Int ans = 0;
		
		for (int i = 0; i < B; i++) {			
			cin >> Qi[i];

			whole_cost[i] = 0LL;

			for (int j = 0; j < Qi[i]; j++) {
				cin >> C[i][j][0] >> C[i][j][1];
				whole_cost[i] += P[C[i][j][0]] * C[i][j][1];
			}

			Int l = 1, h = 1000000000LL, m;

			for ( ; l <= h; ) {
				m = (l + h) / 2;

				Int cs = whole_cost[i] * m;

				if (cs <= D) {
					ans = max(ans, m);
					l = m + 1;
				} else {
					h = m - 1;
				}
			}
		}

		cout << ans << "\n";
	}
    return 0;
}
