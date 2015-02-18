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

const int MAXN = 110;

int N, Q;
int P[MAXN];
vector<int> tree[MAXN];

void dfs_xor(int node) {
	P[node] ^= 1;

	for (int i = 0; i < (int) tree[node].size(); i++) {
		dfs_xor(tree[node][i]);
	}
}

int dfs_sum(int node) {
	int ans = P[node];

	for (int i = 0; i < (int) tree[node].size(); i++) {
		ans += dfs_sum(tree[node][i]);
	}
	return ans;
}

int main(void) {
	for ( ; scanf("%d%d", &N, &Q) == 2; ) {
		for (int i = 0; i < MAXN; i++) {
			tree[i].clear();
			P[i] = 0;
		}
		for (int i = 0; i < N - 1; i++) {
			int A, B;
			scanf("%d%d", &A, &B);
			tree[A].push_back(B);
		}
		
		for (int i = 0; i < Q; i++) {
			int A, B;
			scanf("%d%d", &A, &B);
			
			if (A == 0) {
				dfs_xor(B);
			} else {
				printf("%d\n", dfs_sum(B));
			}
		}
	}
    return 0;
}
