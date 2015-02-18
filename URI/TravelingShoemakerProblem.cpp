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

const int MAXN = 510;

int N, C, K;
int B[MAXN];

vector<int> belong[MAXN], color[MAXN];
bool ok, vis[MAXN];

void dfs(int s, int c, int p) {
	vis[s] = true;

	if (ok) return;
	
	if (p == N) {
		ok = true;
	}
	
	for (int i = 0; i < (int) color[c].size(); i++) {
		int u = color[c][i];
		int n_c = c;
		for (int j = 0; j < belong[u].size(); j++) {
			if (belong[u][j] != c) {
				n_c = belong[u][j];
			}
		}
		if (!vis[u]) {
			dfs(u, n_c, p + 1);			
		} 
	}
	vis[s] = false;
}

int main(void) {
	for ( ; cin >> N >> C && N + C != 0; ) {
		for (int i = 0; i < MAXN; i++) {
			belong[i].clear();
			color[i].clear();
		}
		for (int i = 0; i < C; i++) {
			cin >> K;
			for (int j = 0; j < K; j++) {
				cin >> B[j];
				color[i].push_back(B[j]);
				belong[B[j]].push_back(i);
			}
		}

		int id = -1;
		ok = false;

		for (int i = 0; !ok && i < N; i++) {
			for (int j = 0; !ok && j < belong[i].size(); j++) {
				memset(vis, false, sizeof(vis));
				dfs(i, belong[i][j], 1);
				if (ok) {
					id = i;
					ok = true;
				}
			}	
		} 
		
		cout << id << "\n";
	}
    return 0;
}
