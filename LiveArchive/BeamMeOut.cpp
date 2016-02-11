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

const int MAXN = 50004;

int N;
bool cycle;
vector<int> graph[MAXN], rev[MAXN];
int vis[MAXN];

void dfsCycle(int x) {
	vis[x] = 1;

	for (int i = 0; i < (int) graph[x].size(); i++) {
		int u = graph[x][i];

		if (vis[u] == 0) {
			dfsCycle(u);
		} else if (vis[u] == 1) {
			cycle = true;
		}
	}
	vis[x] = 2;
}

void dfs(int x) {
	vis[x] = 1;

	for (int i = 0; i < (int) rev[x].size(); i++) {
		int u = rev[x][i];

		if (!vis[u]) {
			dfs(u);
		}
	}
}

int main(void) {
	cin >> N;

	bool reach = true;
	cycle = false;
	
	for (int i = 1; i < N; i++) {
		int A, B;
		cin >> A;

		for (int j = 0; j < A; j++) {
			cin >> B;
			graph[i].push_back(B);
			rev[B].push_back(i);

			
			if (B == i) {
				cycle = true;
			}
		}
	}
	
	dfsCycle(1);

	memset(vis, 0, sizeof(vis));

	dfs(N);

	for (int i = 1; i <= N; i++) {
		if (vis[i] == 0) {
			reach = false;
		}
	}

	if (reach) {
		cout << "PARDON ";

		if (cycle) {
			cout << "UNLIMITED\n";
		} else {
			cout << "LIMITED\n";
		}
	} else {
		cout << "PRISON ";

		if (cycle) {
			cout << "UNLIMITED\n";
		} else {
			cout << "LIMITED\n";
		}
	}
	return 0;
}
