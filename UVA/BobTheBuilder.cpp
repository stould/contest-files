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

const int MAXN = 10010;

int T;
int N, L;
bool vis[MAXN];
int ans, pr[MAXN];

void dfs(int x) {
	vis[x] = true;

	int above = 0;

	for (int i = 0; i <= 31; i++) {
		if (x & (1 << i)) {
			if (x + (1 << i) <= L) {
				if (!vis[x + (1 << i)]) {
					above += 1;
					pr[x + (1 << i)] = x;
					dfs(x + (1 << i));
				}
			}
		}
	}
	
	if (above == 0) {
		while (x != -1) {
			cout << x << " ";
			x = pr[x];
		}
		cout << "\n";
		ans += 1;
	}
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> L;

		ans = 0;

		memset(vis, false, sizeof(vis));
		memset(pr, -1, sizeof(pr));

		for (int i = 0; i < N; i++) {
			int x;
			cin >> x;

			dfs(x);
		}

		cout << "Case " << t << ": " << ans << "\n";
	}
    return 0;
}
