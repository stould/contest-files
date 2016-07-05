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

const int MAXN = 300005;

int N;
int P[MAXN];

int sparse_gcd[22][MAXN];
int sparse_min[22][MAXN];
int pw[MAXN];

void build_sparse() {
	pw[1] = 0;
	
	for (int i = 0; i < N; i++) {
		sparse_gcd[0][i] = P[i];
		sparse_min[0][i] = P[i];

		if (i > 1) {
			pw[i] = pw[i - 1] + ((i & (-i)) == i);
		}
	}
	
	for (int i = 1; (1<<i) <= N; i++) {
		for (int j = 0; j + (1 << i) <= N; j++) {			
			sparse_min[i][j] = min(sparse_min[i - 1][j], sparse_min[i - 1][j + (1 << (i - 1))]);
			sparse_gcd[i][j] = gcd(sparse_gcd[i - 1][j], sparse_gcd[i - 1][j + (1 << (i - 1))]);
		}
	} 
}

bool query(int l, int r) {	
	int lg = 1;

	while (lg <= l - r) {
		lg *= 2;
	}
	lg /= 2;
	

	int s_min = min(sparse_min[lg][l], sparse_min[lg][r - (1 << lg) + 1]);
	int s_gcd = gcd(sparse_gcd[lg][l], sparse_gcd[lg][r - (1 << lg) + 1]);	

	return s_min == s_gcd;
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	build_sparse();

	vector<int> ans;
	
	int l = 0, h = N, m;
	int best = -1;
	
	while (l <= h) {
		m = l + (h - l) / 2;
		
		bool found = false;
		
		for (int j = 0; j + m < N; j++) {
			if (query(j, j + m)) {
				found = true;
				break;
			}
		}
		
		if (found) {
			best = max(best, m);
			l = m + 1;
		} else {
			h = m - 1;
		}
	}

	for (int j = 0; j + best < N; j++) {
		if (query(j, j + best)) {
			ans.push_back(j + 1);
		}
	}
	
	cout << ans.size() << " " << best << "\n";

	for (int i = 0; i < (int) ans.size(); i++) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << "\n";
	
	return 0;
}
