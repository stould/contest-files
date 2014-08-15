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

const int INF = INT_MAX / 3;

int T;
string S;
bool vis[30], seen[30];
int cost[30];
vector<int> graph[30];

vector<int> order;

vector<string> split(string st) {
	vector<string> ans;
	istringstream ss(st);
	string buff;

	for ( ; ss >> buff; ) {
		ans.push_back(buff);
	}

	return ans;
}

void dfs(int x) {
	vis[x] = true;

	for (auto& i: graph[x]) {
		if (!vis[i]) {
			dfs(i);
		}
	}

	order.push_back(x);
}

int dp[30];

int func(int id) {
	if (graph[id].empty()) {
		return cost[id];
	} else {
		int& ans = dp[id];

		if (ans == -1) {
			ans = cost[id];
			
			for (auto& i: graph[id]) {
				chmax(ans, cost[id] + func(i));
			}
		}

		return ans;
	}
}

int main(void) {
	cin >> T;
	getline(cin, S);
	getline(cin, S);

	for ( ; T--; ) {
		order.clear();

		for (int i = 0; i < 30; i++) {
			cost[i] = 0;
			dp[i] = -INF;
			vis[i] = seen[i] = false;
			graph[i].clear();
		}

		while (getline(cin, S) && S != "") {
			vector<string> vs = split(S);
			if (vs.empty()) break;
			int id = vs[0][0] - 'A';

			seen[id] = true;
			
			cost[id] = stoi(vs[1]);
			
			if (vs.size() > 2) {
				for (auto& i: vs[2]) {
					graph[i - 'A'].push_back(id);
				}
			}
		}

		for (int i = 0; i < 26; i++) {
			if (!vis[i] && seen[i]) {
				dfs(i);
			}
		}
		
		reverse(order.begin(), order.end());
				
		memset(dp, -1, sizeof(dp));

		for (auto& i: order) {
			dp[i] = cost[i];
		}

		dp[order[0]] = cost[order[0]];

		for (int i = 0; i < order.size(); i++) {
			int u = order[i];
			for (int j = 0; j < (int) graph[u].size(); j++) {
				int v = graph[u][j];
				if (dp[v] < dp[u] + cost[v]) {
					dp[v] = dp[u] + cost[v];
				}
			}
		}

		int ans = *max_element(dp, dp + 30);

		cout << ans << "\n";
		if (T != 0) cout << "\n";
	}
    return 0;
}
