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

int N, M;
bool react[60][60], vis[60];
int chain;

void dfs(int node, int p) {
	vis[node] = true;
	chain++;

	for (int i = 1; i <= N; i++) {
		if (react[node][i] && !vis[i]) {
			dfs(i, node);
		}
	}
}

int main(void) {
	scanf("%d%d", &N, &M);

	for (int i = 0; i < M; i++) {
		int A, B;
		scanf("%d%d", &A, &B);
		react[A][B] = react[B][A] = true;
	}

	Int ans = 1;
	memset(vis, false, sizeof(vis));

	for (int i = 1; i <= N; i++) {
		chain = 0;
		dfs(i, -1);
		ans *= (pow(2.0, chain - 1));
	}
	cout << ans << endl;

    return 0;
}
