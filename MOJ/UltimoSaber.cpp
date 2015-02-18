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

const int MAXN = 10005;

int N, K, M;
queue<int> q;
int vis[MAXN];

vector<int> graph[MAXN];

int main(void) {
	for ( ; cin >> N >> K >> M && N + M + K != 0; ) {
		memset(vis, 63, sizeof(vis));
		for (int i = 0; i < MAXN; i++) {
			graph[i].clear();
		}
		for (int i = 0; i < K; i++) {
			int p;
			cin >> p;

			q.push(p);
			vis[p] = 0;
		}
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		vector<int> ans;
		int ans_cnt = 0;
		for ( ; !q.empty(); ) {
			int now = q.front();
			q.pop();

			for (int i = 0; i < (int) graph[now].size(); i++) {
				int next = graph[now][i];

				if (vis[next] > vis[now] + 1) {
					vis[next] = vis[now] + 1;
					q.push(next);
					ans_cnt = max(ans_cnt, vis[next]);
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			if (vis[i] == ans_cnt) ans.push_back(i);
		}
		for (int i = 0; i < (int) ans.size(); i++) {
			if (i > 0) printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	}
    return 0;
}
