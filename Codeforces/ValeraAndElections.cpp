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

int N;

vector<pair<int, int> > graph[MAXN];
vector<int> ans;

int fix[MAXN];
int mark[MAXN];

void dfs(int x, int p) {
	int i;

	mark[x] = fix[x];

	for (i = 0; i < (int) graph[x].size(); i++) {
		int u = graph[x][i].first;
		int t = graph[x][i].second;

		if (u != p) {
			dfs(u, x);
			mark[x] += mark[u];
		}
	}
}

int main(void) {
	N = in();

	int A, B, C;

	int i;

	memset(fix, 0, sizeof(fix));

	for (i = 0; i < N - 1; i++) {
		A = in();
		B = in();
		C = in();

		graph[A].push_back(make_pair(B, C));		
		graph[B].push_back(make_pair(A, C));		

		if (C == 2) {
			fix[A] = fix[B] = 1;
		}
	}

	dfs(1, -1);

	for (i = 1; i <= N; i++) {
		if (mark[i] == 1 && fix[i] == 1) {
			ans.push_back(i);
		}
	}

	printf("%d\n", (int) ans.size());

	for (i = 0; i < (int) ans.size(); i++) {
		printf("%d ", ans[i]);
	}

	printf("\n");

    return 0;
}