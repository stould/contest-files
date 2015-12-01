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

const int MAXN = 10005;

int N;
vector<int> G[MAXN];
int vis[MAXN];

pair<int, int> diam(int s) {
	queue<int> q;
	q.push(s);

	memset(vis, 62, sizeof(vis));

	vis[s] = 0;
	
	int ans = 0;
	int id = s;
	
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < (int) G[now].size(); i++) {
			int u = G[now][i];

			if (vis[u] > vis[now] + 1) {
				vis[u] = vis[now] + 1;
				q.push(u);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (ans < vis[i]) {
			ans = vis[i];
			id = i;
		}
	}

	return make_pair(id, ans);
}

int main(void) {
	while (cin >> N && N != -1) {
		for (int i = 0; i <= N; i++) {
			G[i].clear();
		}
		for (int i = 2; i <= N; i++) {
			int P;
			cin >> P;

			G[i].push_back(P);
			G[P].push_back(i);
		}

		pair<int, int> af = diam(1);
		pair<int, int> bf = diam(af.first);
		
		int ans = (bf.second + 1) / 2;
		
		cout << ans << endl;
	}
	return 0;
}
