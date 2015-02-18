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

const Int MOD = 1000000007LL;
const int INF = INT_MAX / 4;

int T;
int N, M;
map<int, int> dp[1010][1010];
map<int, int> mark[1010][1010];

vector<int> C[1010];

int smaller(int hei, int color) {
	int l = 0, h = (int) C[color].size(), m;

	int ans = INF;
	
	for ( ; l <= h; ) {
		m = (l + h) / 2;

		if (C[color][m] >= hei) {
			l = m + 1;
		} else {
			ans = min(ans, C[color][m]);
			h = m - 1;
		}
	}
	
	return ans;
}

Int func(int id, int h, int c) {
	if (mark[id][h][c] == false) {
		mark[id][h][c] == true;
		
		dp[id][h][c] = 0LL;

		bool seen = false;
		
		for (int i = 0; i <= 1000; i++) {
			if (C[i].empty()) continue;
			
			int next = smaller(h, i);

			//	cout << h << " " << c << " - " << next << " " << i << "\n";
			if (next < h) {
				dp[id][h][c] += 1 + func(id + 1, next, i);
				seen = true;
			}
		}
	}
	
	return dp[id][h][c];
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M;

		int cl, cc;
		
		for (int i = 0; i < N; i++) {
			cin >> cl >> cc;

			C[cc].push_back(cl);
		}

		for (int i = 0; i <= 1000; i++) {
			sort(C[i].rbegin(), C[i].rend());
		}

		for (int i = 0; i <= 1000; i++) {
			for (int j = 0; j <= 1000; j++) {
				mark[i][j].clear();
			}
		}

		Int ans = func(0, 1001, 0);

		cout << ans << "\n";
	}
	
    return 0;
}
