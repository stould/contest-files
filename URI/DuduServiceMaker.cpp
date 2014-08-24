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
bool vis[MAXN];
vector<int> graph[MAXN];
vector<int> order;

bool ok;

void dfs1(int x) {
	vis[x] = true;

	for (const auto& i: graph[x]) {
		if (!vis[i]) {
			dfs1(i);
		}
	}

	order.push_back(x);
}

void dfs2(int x) {
	vis[x] = true;

	for (const auto& i: graph[x]) {
		if (!vis[i]) {
			dfs2(i);
		} else {
			ok = false;
		}
	}
}

int main(void) {
	cin >> T;
	for ( ; T--; ) {
		cin >> N >> M;

		order.clear();

		for (int i = 0; i < MAXN; i++) {
			graph[i].clear();
			vis[i] = false;
		}

		int A, B;

		for (int i = 0; i < M; i++) {
			cin >> A >> B;
			A--;
			B--;
			graph[A].push_back(B);
		}

		for (int i = 0; i < N; i++) {
			if (!vis[i]) {
				dfs1(i);
			}
		}

		reverse(order.begin(), order.end());
		memset(vis, false, sizeof(vis));

		ok = true;

		for (int i = 0; ok && i < N; i++) {
			if (!vis[i]) {
				dfs2(i);
			}
		}

		if (!ok) {
			cout << "SIM\n";
		} else {
			cout << "NAO\n";
		}
	}
    return 0;
}
