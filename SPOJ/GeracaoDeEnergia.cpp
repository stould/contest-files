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

const Int INF = 100101010010101010LL;
const int MAXN = 10010;

int N, V;
int X[MAXN], Y[MAXN], C[MAXN];
int deg[MAXN], prv[MAXN];
bool vis[MAXN];

int dfs(int node, int gen) {	
	int ans = 0;
	
	if (gen >= V) {
		if (!vis[node]) {
			ans = 1;
		}
		vis[node] = true;
	} else {
		vis[node] = true;
		
		ans = dfs(prv[node], gen + C[node]);
	}

	return ans;
}

int main(void) {
	for ( ; scanf("%d%d", &N, &V) == 2; ) {
		if (N == 0 && V == 0) {
			break;
		}

		for (int i = 0; i < N; i++) {
			scanf("%d%d%d", &X[i], &Y[i], &C[i]);

			double dst = INF;
			int index = -1;
			
			for (int j = 0; j < i; j++) {
				double curr_dst = hypot(X[i] - X[j], Y[i] - Y[j]);

				if (curr_dst < dst) {
					dst = curr_dst;
					index = j;
				}
			}
			
			deg[index] += 1;
			prv[i] = index;			
		}

		vector<int> leaf;

		for (int i = 0; i < N; i++) {
			if (deg[i] == 0) {
				leaf.push_back(i);
			}
		}

		int ans = 0;
		
		for (int i = 0; i < (int) leaf.size(); i++) {
			ans += dfs(leaf[i], C[leaf[i]]);
		}

		printf("%d\n", ans);
	}
    return 0;
}
