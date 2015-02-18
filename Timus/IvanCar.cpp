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

int A, B, N, M;
int dist[MAXN];
vector<edge> graph[MAXN];

struct MyCmp {
	bool operator()(pair<int, bool> a, int pair<int, bool> b) {
		return dist[a.first] > dist[b.first];
	}
};

struct edge {
	int to;
	bool up;

	edge() {}

	edge(int to, bool up): to(to), up(up) {}
}

int func(void) {
	priority_queue<pair<int, bool>, vector<pair<int, bool> >, MyCmp> q;
	memset(dist, 63, sizeof(dist));
	dist[A] = 0;
	q.push(make_pair(A, true));
	q.push(make_pair(A, false));

	for ( ; !q.empty(); ) {
		int now = q.top().first;
		bool up = q.top().second;

		q.pop();

		for (int i = 0; i < (int) graph[now].size(); i++) {
			int u = graph[now][i].to;
			bool sent = graph[now][i].up;
			int add = (up ^ sent ? 1 : 0);

			if (dist[now] + add < dist[u]) {
				dist[u] = dist[now] + add;
				q.push(u);
			}
		}
	}
	return dist[B];
}

int main(void) {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &A, &B);
		graph[A].push_back(edge(B, true));
		graph[B].push_back(edge(A, false));
	}
	scanf("%d%d", &A, &B);
	printf("%d\n", func());
    return 0;
}
