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
const int INF = INT_MAX / 4;

int N, C, S, B;
vector<pair<int, int> > GA[MAXN], GB[MAXN];
int cnt[MAXN];
int dist[MAXN];

int shortestPath(int start, int end) {
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, start));

	fill(dist, dist + N + 1, INF);

	dist[start] = 0;

	while (!q.empty()) {
		int node = q.top().second;
		int curr_dist = -q.top().first;
		q.pop();

		if (curr_dist > dist[node]) continue;
		
		for (int i = 0; i < (int) GA[node].size(); i++) {
			int next = GA[node][i].first;
			int wei  = GA[node][i].second;

			if (dist[next] > dist[node] + wei) {
				dist[next] = dist[node] + wei;
				q.push(make_pair(-dist[next], next));
			}
		}
	}
	
	return dist[end];
}

int canReeach(int start, int len) {
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, start));

	fill(dist, dist + N + 1, INF);

	dist[start] = 0;

	while (!q.empty()) {
		int node = q.top().second;
		int curr_dist = -q.top().first;
		q.pop();

		if (curr_dist > dist[node]) continue;
		
		for (int i = 0; i < (int) GA[node].size(); i++) {
			int next = GA[node][i].first;
			int wei  = GA[node][i].second;

			if (dist[next] > dist[node] + wei) {
				dist[next] = dist[node] + wei;
				q.push(make_pair(-dist[next], next));
			}
		}
		for (int i = 0; i < (int) GB[node].size(); i++) {
			int next = GB[node][i].first;
			int wei  = GB[node][i].second;

			if (dist[next] > dist[node] + wei) {
				dist[next] = dist[node] + wei;
				q.push(make_pair(-dist[next], next));
			}
		}
	}
	
	int ans = 0;

	for (int i = 0; i <= N; i++) {
		if (dist[i] <= len) {
			ans += cnt[i];
		}
	}
	
	return ans;
}

int main(void) {
	cin >> N >> C >> S >> B;

	int P, Q, X;
	
	for (int i = 0; i < C; i++) {
		cin >> P >> Q >> X;
		GA[P].push_back(make_pair(Q, X));
		GA[Q].push_back(make_pair(P, X));
	}

	for (int i = 0; i < S; i++) {
		cin >> P >> Q >> X;
		GB[P].push_back(make_pair(Q, X));
		GB[Q].push_back(make_pair(P, X));
	}

	for (int i = 0; i < B; i++) {
		cin >> P;
		
		cnt[P] += 1;
	}

	cin >> P >> Q;

	int len = shortestPath(P, Q);
	int reach = canReeach(Q, len);

	cout << reach << endl;
	
	
	return 0;
}
