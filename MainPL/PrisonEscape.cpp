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

const int MAXN = 200010;

int N, M;
int pris[MAXN];
vector<int> tree[MAXN];
bool vis[MAXN];
bool reach_leaf, reach_pris;

void dfs(int node, int parent) {
	vis[node] = true;

	for (int i = 0; i < (int) tree[node].size(); i++) {
		int u = tree[node][i];

		if (tree[u].size() == 1) {
			reach_leaf = true;
		}

		if (pris[u]) {
			reach_pris = true;
		}
		
		if (!vis[u] && !pris[u]) {
			dfs(u, node);
		}
	}
}

int main(void) {
	cin >> N >> M;

	int A, B;
	
	for (int i = 0; i < M; i++) {
		cin >> A;
		pris[A] = 1;
	}
	
	for (int i = 0; i < N; i++) {
		cin >> A >> B;

		tree[A].push_back(B);
		tree[B].push_back(A);
	}

	int ans = 0;
	
	for (int i = 1; i <= N + 1; i++) {
		if (!vis[i] && !pris[i] && tree[i].size() != 1) {
			reach_pris = false;
			reach_leaf = false;
			
			dfs(i, -1);

			if (reach_pris && reach_leaf) {
				ans += 1;
			}
		}
	}

	for (int i = 1; i <= N + 1; i++) {
		if (tree[i].size() == 1) {
			if (pris[tree[i][0]]) {
				ans += 1;
			}
			if (pris[i]) {
				ans = -1;
				break;
			}
		}
	}

	cout << ans << "\n";
	
    return 0;
}
