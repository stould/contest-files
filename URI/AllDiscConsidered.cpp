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

int N, M, D;
vector<int> graph[MAXN], order;
bool vis[MAXN];

void dfs(int x) {
	vis[x] = true;

	for (const auto& i: graph[x]) {
		if (!vis[i]) {
			dfs(i);
		}
	}

	order.push_back(x);
}

int main(void) {
	for ( ; cin >> N >> M >> D && !(N == 0 && M == 0 && D == 0); ) {
		order.clear();
		for (int i = 1; i <= N + M; i++) {
			graph[i].clear();
			vis[i] = false;
		}

		int A, B;

		for (int i = 0; i < D; i++) {
			cin >> A >> B;
			graph[B].push_back(A);
		}
		
		vector<int> non_dep;
		
		for (int i = 1; i <= N + M; i++) {
			if (!vis[i]) {
				if (graph[i].empty()) {
					non_dep.push_back(i);
				} else {
					dfs(i);
				}
			}
		}

		int ans = 3;
		int curr = order[0];

		reverse(order.begin(), order.end());

		for (int i = 0; i < (int) order.size(); i++) {
			if ((curr <= N && order[i] > N) || (curr > N && order[i] <= N)) {
				ans += 1;
			}
			curr = order[i];
		}		

		cout << ans << "\n";
	}
    return 0;
}
