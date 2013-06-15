#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

#define S(ZZ) (ZZ)*(ZZ)
#define FOR(ii, i0, in) for((ii)=(i0); (ii)<(in); (ii)++)
#define FOR2d(ii, jj, i0, j0, in, jn) FOR(ii, i0, in) FOR(jj, j0, jn)
#define FOR3d(kk, ii, jj, k0, i0, j0, kn, in, jn) FOR(kk, k0, kn) FOR(ii, i0, in) FOR(jj, j0, jn)
#define INF 999999999L

const int MAXN = 102;
typedef pair<int, int> Point;

int main() {
	int t = 1, n, N, E, i, j, k;
	while ((cin >> N) && (n = N)) {
		double g[MAXN][MAXN];
		for(int i = 1; i <= N; i++) {
		    for(int j = 1; j <= N; j++) {
		        g[i][j] = INF;
		    }
		}

		while ((cin >> i) && i) while ((cin >> j) && j) g[i][j] = 1;
		FOR3d(k, i, j, 1, 1, 1, N+1, N+1, N+1) g[i][j] = min(g[i][j], max(g[i][k], g[k][j]));

		cin >> t;
		while (t--) {
			cin >> i;
			vector<int> ans;
			FOR(j, 1, N+1) if (g[i][j] == INF)	ans.push_back(j);
			cout << ans.size();
			FOR(j, 0, ans.size()) cout << " " << ans[j];
			cout << endl;
		}
	}
	return 0;
}
