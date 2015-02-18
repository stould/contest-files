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

const int MAXN = 60005;;

int N, M, A, B;

vector<int> graph[MAXN];
bool vis[MAXN];

void dfs(int x) {
	vis[x] = true;

	for (int i = 0; i < (int) graph[x].size(); i++) {
		int u = graph[x][i];

		if (!vis[u]) {
			dfs(u);
		}
	}
}

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> A >> B;

		graph[A].push_back(B);
		graph[B].push_back(A);
	}

	int ans = 0;

   	for (int i = 1; i <= N; i++) {
		if (!vis[i]) {
			ans += 1;
			dfs(i);
		}
	}

	cout << ans << "\n";

    return 0;
}
