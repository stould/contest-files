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

int N;
int id;
map<string, int> mp;
vector<int> graph[4010];
int vis[4010];

void func(string s) {
	if (mp[s] == 0) {
		mp[s] = id;
		id++;
	}
}

int bfs(int x, int y) {
	queue<int> q;
	q.push(x);
	memset(vis, 63, sizeof(vis));
	vis[x] = 0;

	for ( ; !q.empty(); ) {
		int now = q.front();
		q.pop();
		if (now == y) return vis[now];

		for (int i = 0; i < (int) graph[now].size(); i++) {
			int next = graph[now][i];

			if (vis[next] > vis[now] + 1) {
				vis[next] = vis[now] + 1;
				q.push(next);
			}
		}
	}
	return -1;
}

int main(void) {
	cin >> N;
	string A, B;
	id = 1;
	set<string> sp;
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		func(A);
		func(B);
		sp.insert(A);
		sp.insert(B);
		graph[mp[A]].push_back(mp[B]);
	}
	vector<string> vp(sp.begin(), sp.end());
	for (int i = 0; i < vp.size(); i++) {
		if (i == 0) {
			graph[mp[vp[i]]].push_back(mp[vp[i + 1]]);
		} else if (i == vp.size() - 1) {
			graph[mp[vp[i]]].push_back(mp[vp[i - 1]]);
		} else {
			graph[mp[vp[i]]].push_back(mp[vp[i + 1]]);
			graph[mp[vp[i]]].push_back(mp[vp[i - 1]]);
		}
	}
	cin >> A >> B;
	int d = bfs(mp[A], mp[B]);
	cout << d << "\n";
    return 0;
}
