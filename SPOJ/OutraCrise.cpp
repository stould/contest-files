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

const int MAXN = 100005;

int N, T;
bool vis[MAXN];
vector<int> graph[MAXN];

int dfs(int node) {
	if (graph[node].size() == 0) {
		return 1;
	} else {
		vector<int> curr;

		double perc = ceil(T * int(graph[node].size()) / 100.0);
		int sum = 0;

		for (int i = 0; i < (int) graph[node].size(); i++) {
			int now = dfs(graph[node][i]);
			curr.push_back(now);
		}

		sort(curr.begin(), curr.end());
		
		for (int i = 0; i < (int) perc; i++) {
			sum += curr[i];
		}
		return sum;
	}
}

int main(void) {
	for ( ; scanf("%d%d", &N, &T) == 2 && N + T != 0; ) {
		int U;

		for (int i = 0; i <= N; i++) graph[i].clear();

		for (int i = 1; i <= N; i++) {
			scanf("%d", &U);
			graph[U].push_back(i);
		}

		int ans = dfs(0);

		printf("%d\n", ans);
	} 
    return 0;
}
