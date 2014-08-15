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

const int MAXN = 1010;
const double INF = 1010101010100.0;

int N, C[MAXN];
char buff1[20], buff2[20];
vector<int> tree[MAXN];
int pos[MAXN][55][3];
bool vis[MAXN], mark[MAXN][55];

vector<int> order;

double dp[1010][55];

int dfs(int x) {
	vis[x] = true;

	for (auto& i: tree[x]) {
		if (!vis[i]) dfs(i);
	}

	order.push_back(x);
}

double func(int id, int site, int parent) {
	if (tree[id].size() == 1 && tree[id][0] == parent) {
		return 0.0;
	}

	double& ans = dp[id][site];
	
	if (!mark[id][site]) {
		mark[id][site] = true;
		ans = 0.0;
		
		for (int i = 0; i < (int) tree[id].size(); i++) {
			int next = tree[id][i];
			
			if (next == parent) continue;

			double best = INF;

			for (int j = 1; j <= C[next]; j++) {
				double dist = hypot(pos[id][site][0] - pos[next][j][0], pos[id][site][1] - pos[next][j][1]);
				
				chmin(best, dist + func(next, j, id));
			}
			ans += best;
		}
	}

	return ans;
}

int main(void) {
	for ( ; scanf("%d", &N) && N != 0; ) {
		map<string, int> mp;
		int id = 1;
		
		for (int i = 0; i <= N; i++) {
			vis[i] = false;
			tree[i].clear();
		}

		order.clear();

		for (int i = 1; i <= N; i++) {
			scanf("%s%d", buff1, &C[i]);

			string name(buff1);

			mp[name] = id++;

			for (int j = 1; j <= C[i]; j++) {
				scanf("%d%d", &pos[i][j][0], &pos[i][j][1]);
			}
		}
		for (int i = 0; i < N - 1; i++) {
			scanf("%s%s", buff1, buff2);
			
			string name1(buff1);
			string name2(buff2);

			int id1 = mp[name1];
			int id2 = mp[name2];

			tree[id1].push_back(id2);
			tree[id2].push_back(id1);
		}

		for (int i = 1; i <= N; i++) {
			if (!vis[i]) dfs(i);
		}

		memset(mark, false, sizeof(mark));

		double ans = INF;

		for (int i = 1; i <= C[order[N-1]]; i++) {
			chmin(ans, func(order[N-1], i, -1));
		}

		printf("%.1lf\n", ans);
	}
    return 0;

}
