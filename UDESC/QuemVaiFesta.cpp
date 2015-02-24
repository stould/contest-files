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

int N;
vector<int> graph[MAXN];
bool vis[MAXN];

int dfs(int x) {
	vis[x] = true;

	int ans = 1;
	
	for (int i = 0; i < (int) graph[x].size(); i++) {
		int u = graph[x][i];

		if (!vis[u]) {
			ans += dfs(u);
		}
	}

	return ans;
}

int main(void) {
	for ( ; scanf("%d", &N) && N != 0; ) {
		for (int i = 0; i < MAXN; i++) {
			graph[i].clear();
			vis[i] = false;
		}

		int A, B;
		for (int i = 0; i < N; i++) {
			scanf(" %*c %d %*c%d %*c", &A, &B);
			graph[A].push_back(B);
			graph[B].push_back(A);
		}
		queue<int> q;
		q.push(1);
		vis[1] = true;

		int ans = 0;

		for ( ; !q.empty(); ) {
			int now = q.front();
			q.pop();
			

			ans += 1;

			for (int i = 0; i < (int) graph[now].size(); i++) {
				int u = graph[now][i];

				if (!vis[u]) {
					vis[u] = true;
					q.push(u);					
				}
			}
		}
		
		printf("%d\n", ans);
	}
    return 0;
}
