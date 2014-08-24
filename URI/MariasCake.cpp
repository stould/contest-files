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

unordered_map<int, int> dp[MAXN];
unordered_map<int, bool> mark[MAXN];

int func(int id, int cost) {
	if (cost > D) return -INF;
	if (id == B) {
		return 0;
	} else {
		int& ans = dp[id][cost];

		if (!mark[id][cost]) {
			mark[id][cost] = true;
			ans = func(id + 1, cost);

			int cs = 0;
			
			for (int j = 0; j < Qi[id]; j++) {
				cs += P[C[id][j][0]] * C[id][j][1];
			}

			for (int us = 1; ; us++) {
				int ns = cs * us;
				if (ns + cost > D) break;
				chmax(ans, us + func(id + 1, cost + ns));
				
			}
		}

		return ans;
	}
}
					 
int main(void) {
	cin >> T;
	
	for ( ; T--; ) {
		cin >> D >> I >> B;
		
		for (int i = 0; i < I; i++) {
			cin >> P[i];
		}
		
		for (int i = 0; i < B; i++) {			
			cin >> Qi[i];
			for (int j = 0; j < Qi[i]; j++) {
				cin >> C[i][j][0] >> C[i][j][1];
			}
		}

		for (int i = 0; i < MAXN; i++) {
			mark[i].clear();
		}
		
		cout << func(0, 0) << "\n";
	}
    return 0;
}
