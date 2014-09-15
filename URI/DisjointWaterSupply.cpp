#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) {
    a = (a > b) ? b : a;
}
template<typename T> void chmax(T& a, T b) {
    a = (a < b) ? b : a;
}
int in() {
    int x;
    scanf("%d", &x);
    return x;
}

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 1010;

int N, M;
vector<int> graph[MAXN];
bool mark[MAXN][MAXN], dp[MAXN][MAXN];

bool func(int x, int y) {	
	if (x > y) swap(x, y);
	if (x == y) {
		return x == 0;
	}
	
    bool& ans = dp[x][y];

    if (!mark[x][y]) {
		mark[x][y] = true;

        ans = false;
		
		for (int i = 0; !ans && i < (int) graph[y].size(); i++) {
			ans |= func(x, graph[y][i]);
		}
	}

    return ans;
}

int main(void) {
	for ( ; scanf("%d%d", &N, &M) == 2; ) {
		for (int i = 0; i < MAXN; i++) {
			graph[i].clear();
		}
		int A, B;
		for (int i = 0; i < M; i++) {
			scanf("%d%d", &A, &B);
			A--; B--;
			graph[B].push_back(A);
		}
		int ans = 0;
		
		memset(mark, false, sizeof(mark));

		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (func(i, j)) {
					ans += 1;
				}
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}
