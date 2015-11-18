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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 1010;
const double EPS = 1e-8;

int T, N;
double D;
double X[MAXN], Y[MAXN];
bool vis[MAXN];
vector<int> G[MAXN];

void dfs(int x) {
	vis[x] = true;

	for (int i = 0; i < (int) G[x].size(); i++) {
		int u = G[x][i];

		if (!vis[u]) {
			dfs(u);
		}
	}
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> D;

		for (int i = 0; i <= N; i++) {
			G[i].clear();
			vis[i] = false;
		}
		
		for (int i = 0; i < N; i++) {
			cin >> X[i] >> Y[i];

			for (int j = 0; j < i; j++) {
				double dst = hypot(X[i] - X[j], Y[i] - Y[j]);

				if (dst + EPS <= D) {
					G[i].push_back(j);
					G[j].push_back(i);
				}
			}
		}

		int ans = 0;

		for (int i = 0; i < N; i++) {
			if (!vis[i]) {
				dfs(i);
				ans += 1;
			}
		}

		cout << "Case " << t << ": " << ans << "\n";
		
	}
	return 0;
}
