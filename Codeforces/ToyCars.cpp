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

int N, M[MAXN][MAXN], G[MAXN];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> M[i][j];

			if (M[i][j] == 1) {
				G[i] = -1;
			} else if (M[i][j] == 2) {
				G[j] = -1;
			} else if (M[i][j] == 3) {
				G[i] = G[j] = -1;
			}
		}
	}

	vector<int> ans;

	for (int i = 0; i < N; i++) {
		if (G[i] == 0) {
			ans.push_back(i + 1);
		}
	}

	cout << ans.size() << "\n";
	
	for (int i = 0; i < (int) ans.size(); i++) {
		if (i) cout << " ";
		cout << ans[i];
	}
	return 0;
}
