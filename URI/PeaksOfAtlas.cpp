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

const int MAXN = 1010;

int N, M;
int P[MAXN][MAXN];

int dx[8] = { 0, 0, -1, 1, -1, -1,  1, 1};
int dy[8] = {-1, 1,  0, 0, -1,  1, -1, 1};

int main(void) {
	for ( ; scanf("%d%d", &N, &M) == 2; ) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &P[i][j]);
			}
		}

		vector<pair<int, int> > ans;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				bool ok = true;
				for (int k = 0; k < 8; k++) {
					int pi = i + dx[k];
					int pj = j + dy[k];

					if (pi >= 0 && pi < N && pj >= 0 && pj < M) {
						if (P[pi][pj] >= P[i][j]) {
							ok = false;
						}
					}
				}
				if (ok) ans.push_back(make_pair(i + 1, j + 1));
			}
		}
		if (ans.empty()) {
			printf("-1\n");
		} else {
			sort(ans.begin(), ans.end());
			for (int i = 0; i < (int) ans.size(); i++) {
				printf("%d %d\n", ans[i].first, ans[i].second);
			}
		}
		printf("\n");
	}
    return 0;
}
