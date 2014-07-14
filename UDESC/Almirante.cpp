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

const int MAXN = 1010;
int V, E;
int dist[MAXN], pr[MAXN];
bool used[MAXN][MAXN];
vector<pair<int, int> > graph[MAXN];
vector<pair<int, int> > prob;
struct Cmp {
	bool operator()(int a, int b) {
		return dist[a] > dist[b];
	}
};

int func() {
	priority_queue<int, vector<int>, Cmp> pq;
	memset(dist, 63, sizeof(dist));
	memset(pr, -1, sizeof(pr));
	dist[1] = 0;
	pq.push(1);

	for ( ; !pq.empty(); ) {
		int now = pq.top();
		pq.pop();

		for (int i = 0; i < (int) graph[now].size(); i++) {
			int next = graph[now][i].first;
			int cost = graph[now][i].second;

			if (dist[next] > dist[now] + cost) {
				if (used[now][next]) continue;
				dist[next] = dist[now] + cost;
				pq.push(next);
				pr[next] = now;
			}
		}
	}
	int c = V;
	while (c != -1) {
		printf("%d ", c);
		prob.push_back(pr[c], c));
		c = pr[c];
	}
	printf(" - %d \n", dist[V]);
	return dist[V];	
}
int main(void) {
	int A, B, C;
	memset(used, false, sizeof(used));
	for ( ; cin >> V >> E && V + E != 0; ) {
		for (int i = 0; i < E; i++) {
			cin >> A >> B >> C;
			graph[A].push_back(make_pair(B, C));
		}
		int a = func(), b = func();
		cout << a + b << "\n";
	}
    return 0;
}
