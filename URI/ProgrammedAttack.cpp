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
int N, M, S, seen;
int E[MAXN], F[MAXN];
bool vis[MAXN];
vector<int> graph[MAXN], rev[MAXN];
unordered_set<int> cleared;
vector<int> order;

void dfs_1(int x) {
	vis[x] = true;

	for (int i = 0; i < (int) graph[x].size(); i++) {
		if (!vis[graph[x][i]]) {
			dfs_1(graph[x][i]);
		}
	}

	order.push_back(x);
}

bool poss(int x) {
	bool clear = true;
	
	for (int i = 0; i < (int) rev[x].size(); i++) {
		if (!cleared.count(rev[x][i])) {
			clear = false;
		}
	}
	return clear;
}

bool dfs_2(int x) {
	if (poss(x) && S > E[x]) {
		vis[x] = true;
		
		cleared.insert(x);
		S += F[x];

		seen += 1;
		
		for (int i = 0; i < graph[x].size(); i++) {
			if (!vis[graph[x][i]]) {
				dfs_2(graph[x][i]);
			}
		}
		return true;
	} else {
		return false;
	}
}

int main(void) {
	while (cin >> N >> M >> S && !(N == 0 && M == 0 && S == 0)) {
		cleared.clear();
		for (int i = 0; i < N; i++) {
			graph[i].clear();
			rev[i].clear();
			E[i] = F[i] = vis[i] = 0;
		}
		
		for (int i = 0; i < N; i++) {
			cin >> E[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> F[i];
		}
		for (int i = 0; i < M; i++) {
			int A, B;
			cin >> A >> B;

			A -= 1;
			B -= 1;

			graph[A].push_back(B);
			rev[B].push_back(A);
		}

		for (int i = 0; i < N; i++) {
			if (!vis[i]) {
				dfs_1(i);
			}
		}

		reverse(order.begin(), order.end());
		memset(vis, false, sizeof(vis));
		
		seen = 0;

		while (1) {
			bool yet = false;
			for (int i = 0; i < N; i++) {
				if (!vis[order[i]]) {
					if (dfs_2(order[i])) {
						yet = true;
					}
				}
			}
			if (!yet) break;
		}

		if (seen == N) {
			cout << "possivel\n";
		} else {
			cout << "impossivel\n";
		}
		
	}
    return 0;
}
