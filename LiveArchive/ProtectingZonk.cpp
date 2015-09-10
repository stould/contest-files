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
typedef unsigned uint;

const int MAXN = 10005;
const int INF = INT_MAX / 3;

int N, C, D;
int U, V;
vector<int> tree[MAXN];
int dp[MAXN][5][5];

int func(int node, int prev, int down, int up_rem) {
	if (tree[node].size() == 1 && prev != -1) {
		if (up_rem == 0) {
			return 0;
		} else if (up_rem == 1) {
			return min(C, D);
		} else if (up_rem == 2) {
			return D;
		} else {
			return INF;
		}
	} else if (up_rem > 2) {
		return INF;
	} else {
		int& ans = dp[node][down][up_rem];
		
		if (ans == -1) {
			ans = INF;

			int not_use = 0;
			int use_soldier = C;
			
			for (int i = 0; i < (int) tree[node].size(); i++) {
				if (tree[node][i] != prev) {
					not_use += func(tree[node][i], node, max(0, down - 1), up_rem + 1);
				}
			}
			ans = not_use;
		}
		return ans;
	}
}

int main(void) {
	for ( ; cin >> N >> C >> D; ) {
		if (N == 0 && C == 0 && D == 0) break;

		for (int i = 0; i < MAXN; i++) {
			tree[i].clear();
		}
		
		for (int i = 0; i < N - 1; i++) {
			cin >> U >> V;
			
			tree[U].push_back(V);
			tree[V].push_back(U);
		}

		

		int ans = INF;
		
		for (int i = 1; i <= N; i++) {
			if (tree[i].size() == 1) {
				memset(dp, -1, sizeof(dp));
				chmin(ans, func(i, -1, 1, 1, 0));
				cout << i << " " << func(i, -1, 1, 1, 0) <<endl;
			}
		}

		cout << ans << endl;
	}
	return 0;
}
