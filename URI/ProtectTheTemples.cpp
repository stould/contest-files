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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned uint;

const int MAXN = 1115;

int T, N, M;
vector<int> G[MAXN];
int color[MAXN];

void dfs(int node, int c) {
	color[node] = c;

	for (int i = 0; i < (int) G[node].size(); i++) {
		int u = G[node][i];

		if (color[u] == -1) {
			dfs(u, c ^ 1);
		}
	}
}

int main(void) {
	cin >> T;

	while (T--) {
		cin >> N >> M;

		for (int i = 0; i < MAXN; i++) {
			G[i].clear();
			color[i] = -1;
		}

		for (int i = 0; i < M; i++) {
			int A, B;
			cin >> A >> B;

			G[A].push_back(B);
			G[B].push_back(A);
		}

		dfs(1, 0);

		int c0 = 0;
		int c1 = 0;
		
		for (int i = 1; i <= N; i++) {
			if (color[i] == 0) {
				c0 += 1;
			} else {
				c1 += 1;
			}
		}

		cout << max(c0, c1) << "\n";
	
	}
	return 0;
}
