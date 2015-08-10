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

const int MAXN = 21;
const int MAX_BITS = 20;
const int INF = INT_MAX / 3;;

int T, N, M;
int P[MAXN][MAXN];
int dp[MAXN][MAXN][17715];
int valid_mask[17715];
int mask_id[1 << 20];

int conv(int i, int j) {
	return i * M + j;
}
string bin(int x) {
	string ans = "";
	while (x > 0) {
		ans += '0' + (x % 2);
		x /= 2;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int func(int row, int col, int mask) {
	if (col >= M) {
		return func(row + 1, 0, mask);					
	} else if (row >= N) {
		return 0;
	} else {
		int& ans = dp[row][col][mask];

		if (ans == -1) {
			int pass_mask = mask_id[valid_mask[mask] & ~(1 << col)];
			//assert(pass_mask != -1);
			ans = func(row, col + 1, pass_mask);
			
			if (!(valid_mask[mask] & (1 << col))) {				
				int next_mask = valid_mask[mask] | (1 << col);
				if (col + 1 < M) {
					next_mask &= ~(1 << (col + 1));
				}
				//cout << row << " " << col << " check = "<< (valid_mask[mask] & (1 << col)) << " " << bin(valid_mask[mask]) << " " << bin(valid_mask[mask] | (1 << col)) << "\n";
				//assert(next_mask != -1);
				chmax(ans, P[row][col] + func(row, col + 2, mask_id[next_mask]));				
			}
		}
		
		return ans;			  
	}		
}

int main(void) {
	scanf("%d", &T);

	memset(mask_id, -1, sizeof(mask_id));
	
	int cnt = 0;
	for (int i = 0; i < (1 << MAX_BITS); i++) {
		bool ok = true;

		for (int j = 1; j < MAX_BITS; j++) {
			int u = i & (1 << j);
			int v = i & (1 << (j - 1));

			if (u != 0 && v != 0) {
				ok = false;
				break;
			}
		}
		
		if (ok) {
			//cout << cnt << " " << i << "\n";
			valid_mask[cnt] = i;
			mask_id[i] = cnt;
			cnt++;
		}
	}

	for (int test = 1; test <= T; test++) {
		scanf("%d%d", &M, &N);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &P[i][j]);
			}
		}

		memset(dp, -1, sizeof(dp));
		
		printf("Case %d: %d\n", test, func(0, 0, 0));
	}
	
	return 0;
}
