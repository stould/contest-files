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

int T, N, M;
vector<int> graph[MAXN];
bool vis[MAXN];

void clear(void) {
	for (int i = 0; i < MAXN; i++) {
		vis[i] = false;
		graph[i].clear();
	}
}

bool dfs(int x) {
	if (!vis[x]) {
		vis[x] = true;

		for (int i = 0; i < (int) graph[x].size(); i++) {
			int u = graph[x][i];

			if (!vis[u]) {
				dfs(u);
			}
		}

		return true;
	} else {
		return false;
	}
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M;

		clear();

		int A, B;
		
		for (int i = 0; i < M; i++) {
			cin >> A >> B;
			graph[A].push_back(B);
			graph[B].push_back(A);
		}

		int ans = 0;

		for (int i = 1; i <= N; i++) {
			if (dfs(i)) {
				ans += 1;
			}
		}

		cout << (ans * (ans - 1)) / 2 << endl;
	}
	return 0;
}
