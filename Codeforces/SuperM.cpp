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

const int MAXN = 123459;

int N, M;
vector<int> G[MAXN];
int ON[MAXN];
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
		if (vis[i] != 1044266558 && ans < vis[i]) {
			ans = vis[i];
			id = i;
		}
	}

	return make_pair(id, ans);
}

pair<int, int> solve(int r) {
	pair<int, int> a = diam(r);
	pair<int, int> b = diam(a.first);
	pair<int, int> c = diam(b.first);
	pair<int, int> d = diam(c.first);

	return make_pair(min(a.first, min(b.first, min(c.first, d.first))), max(a.second, max(b.second, max(c.second, d.second))));
}

int main(void) {
	cin >> N >> M;

	int A, B;
	
	for (int i = 0; i < N - 1; i++) {
		cin >> A >> B;
		
		G[A].push_back(B);
		G[B].push_back(A);
	}

	for (int i = 0; i < M; i++) {
		cin >> A;
		ON[A] = 1;
	}
	
	for (int i = 1; i <= N; i++) {
		if (G[i].size() == 1 && !ON[i]) {
			int u = i;

			while (1) {
				if (ON[u] || G[u].size() > 1) break;

				int next = G[u][0];

				G[u].clear();

				vector<int>::iterator it = find(G[next].begin(), G[next].end(), u);

				if (it != G[next].end()) {
					G[next].erase(find(G[next].begin(), G[next].end(), u));
				}
				
				u = next;
			}
		}
	}

	int ans = -1;
	int cnt = 0;
	
	for (int i = 1; i <= N; i++) {		
		if (ON[i] && G[i].size() <= 1) {
			ans = i;
			break;			
		}
	}

	for (int i = 1; i <= N; i++) {
		cnt += G[i].size();
	}

	pair<int, int> s = solve(ans);
	
	ans = s.first;
	cnt -= s.second;

	cout << ans << "\n" << cnt << "\n";
	
	return 0;
}
