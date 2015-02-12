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

const int MAXN = 10010;

int N, M;
int vis[MAXN];
int v, are;
vector<int> graph[MAXN];

void dfs(int x, int p) {
	vis[x] = true;

	v++;

	for (int i = 0; i < (int) graph[x].size(); i++) {
		int u = graph[x][i];

		if (u == p) continue;
		are++;
		
		if (!vis[u]) {
			dfs(u, x);
		}
	}
}


int main(void) {
	for ( ; scanf("%d%d", &N, &M) == 2; ) {
		for (int i = 0; i <= N; i++) {
			graph[i].clear();
			vis[i] = false;
		}

		bool safe = true;
		
		for (int i = 0; i < M; i++) {
			int A, B;
			scanf("%d%d", &A, &B);
			graph[A].push_back(B);
			graph[B].push_back(A);

			if (A == B) {
				safe = false;
			}
		}

		for (int i = 1; i <= N; i++) {
			if (!vis[i]) {
				are = 0;
				v = 0;
				dfs(i, -1);
				if (v != are + 1) {
					safe = false;
				}				
			}
		}

		if (safe) {
			cout << "Seguro\n";
		} else {
			cout << "Inseguro\n";
		}
	}
	
    return 0;
}
