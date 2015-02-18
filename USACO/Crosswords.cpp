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

const int MAXN = 55;

int N, M;
string S[MAXN];

bool try_hor(int x, int y) {
	if (y - 1 >= 0 && S[x][y - 1] == '.') {
		return false;
	}
	if (y + 2 >= M) return false;

	for (int i = 1; i <= 2; i++) {
		if (S[x][y + i] == '#') {
			return false;
		}
	}
	
	return true;
}

bool try_ver(int x, int y) {
	if (x - 1 >= 0 && S[x - 1][y] == '.') {
		return false;
	}
	if (x + 2 >= N) return false;

	for (int i = 1; i <= 2; i++) {
		if (S[x + i][y] == '#') {
			return false;
		}
	}
	
	return true;
}

int main(void) {
	freopen("crosswords.in", "r", stdin);
	freopen("crosswords.out", "w", stdout);
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	vector<pair<int, int> > ans;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (S[i][j] == '#') continue;
			if (try_hor(i, j) || try_ver(i, j)) {
				ans.push_back(make_pair(i + 1, j + 1));
			}
		}
	}

	cout << ans.size() << "\n";

	for (int i = 0; i < (int) ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
	
    return 0;
}
