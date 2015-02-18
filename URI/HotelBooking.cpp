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
const int INF = INT_MAX / 3;

int N, M, H;
int Hi[MAXN];
int dist[110][MAXN], ds[MAXN];

vector<pair<int, int> > graph[MAXN];
vector<int> sd_graph[MAXN];

struct state {
	int index, len;

	state(){}

	state(int index, int len):
		index(index),
		len(len)
	{}

	bool operator<(const state& other) const {
		return len > other.len;;
	}
};

void dijkstra(int source_id) {
	priority_queue<state> q;
	q.push(state(Hi[source_id], 0));

	dist[source_id][Hi[source_id]] = 0;

	for ( ; !q.empty(); ) {
		int curr_index = q.top().index;
		int curr_len = q.top().len;

		q.pop();

		if (curr_len > 600) continue;

		sd_graph[Hi[source_id]].push_back(curr_index);

		for (int i = 0; i < (int) graph[curr_index].size(); i++) {
			int next_index = graph[curr_index][i].first;
			int next_len = curr_len + graph[curr_index][i].second;
				
			if (dist[source_id][next_index] > curr_len && next_len <= 600) {
				dist[source_id][next_index] = curr_len;
				q.push(state(next_index, next_len));
			}
		}
	}
}

int func(void) {
	queue<int> q;
	q.push(1);
	
	ds[1] = 0;

	for ( ; !q.empty(); ) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < (int) sd_graph[now].size(); i++) {
			int next = sd_graph[now][i];		

			if (ds[next] > ds[now] + 1) {
				ds[next] = ds[now] + 1;
				q.push(next);
			}
		}		
	}

	return ds[N] == INF ? -1 : ds[N] - 1;
}

int main(void) {
	for ( ; cin >> N && N != 0; ) {
		for (int i = 0; i <= N; i++) {
			graph[i].clear();
			sd_graph[i].clear();

			ds[i] = INF;

			for (int j = 0; j < 110; j++) {
				dist[j][i] = INF;
			}
		}

		int A, B, C;

		cin >> H;

		for (int i = 0; i < H; i++) {
			cin >> Hi[i];
		}

		Hi[H++] = 1;
		Hi[H++] = N;

		cin >> M;

		for (int i = 0; i < M; i++) {
			cin >> A >> B >> C;
			graph[A].push_back(make_pair(B, C));
			graph[B].push_back(make_pair(A, C));
		}

		for (int i = 0; i < H; i++) {
			dijkstra(i);
		}

		cout << func() << "\n";
	}
    return 0;
}
