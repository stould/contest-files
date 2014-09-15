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

const int MAXN = 100005;

int N, M, cnt;
Int val[MAXN];
vector<int> graph[MAXN];

int ini[MAXN], fin[MAXN];
int tree[4 * MAXN], lazy[4 * MAXN];
map<int, int> mnode;

void dfs(int node, int p) {
	ini[node] = cnt;
	mnode[cnt] = node;
	cnt++;

	for (int i = 0; i < (int) graph[node].size(); i++) {
		int u = graph[node][i];

		if (u != p) {
			dfs(u, node);
		}
	}

	fin[node] = cnt - 1;
}

void build(int node, int l, int r) {
	if (l == r) {
		
	}
}

int main(void) {
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &val[i]);
	}
	int A, B;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d%d", &A, &B);
		A--; B--;
		graph[A].push_back(B);
		graph[B].push_back(A);
	}
	cnt = 0;
	dfs(0, -1);

	for (int i = 0; i < M; i++) {
		scanf("%s", buff);
		
		if (strcmp(buff, "SOMA")) {
			scanf("%d", &A);
			A--;
		} else {
			scanf("%d%d", &A, &B);
		}
	}

    return 0;
}
