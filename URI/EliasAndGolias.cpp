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
const int INF = INT_MAX / 3;

int T, N, M, K;
vector<pair<int, int> > graph[MAXN];
int dp1[MAXN], dp2[MAXN][MAXN];
int used[MAXN];
pair<int, int> func(void) {
	priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > q;
	int ans = INF;
	q.push(make_pair(0LL, make_pair(0, 1)));
	dp1[0] = 0;
	used[0] = 1;

	for ( ; !q.empty(); ) {
		int cost = q.top().first;
		int id = q.top().second.first;
		int pass = q.top().second.second;
		
		q.pop();
		
		if (pass > K || dp1[id] < cost) continue;
		
		if (id == N - 1) {
			break;
		}
		
		for (int i = 0; i < (int) graph[id].size(); i++) {
			int next = graph[id][i].first;
			int ec = graph[id][i].second;
			
			if (dp1[next] > dp1[id] + ec) {
				dp1[next] = dp1[id] + ec;
				used[next] = used[id] + 1;
				q.push(make_pair(dp1[id] + ec, make_pair(next, pass + 1)));
			}
		}
	}

	return make_pair(dp1[N-1], used[N-1]);
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> T;

	for ( ; T--; ) {
		cin >> N >> M >> K;
		for (int i = 0; i <= N; i++) {
			graph[i].clear();
			dp1[i] = INF;
			for (int j = 0; j <= K; j++) {
				dp2[i][j] = INF;
			}
		}

		for (int i = 0; i < M; i++) {
			int A, B, C;
			cin >> A >> B >> C;
			graph[A].push_back(make_pair(B, C));
		}

		pair<int, int> ans = func();
		
		if (ans.first >= INF) {
			ans.first = -1;
		} else {
			if (ans.second > K) {
				ans.first = -1;
				priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > q;
				q.push(make_pair(0LL, make_pair(0, 1)));
				dp2[0][1] = 0;
				
				for ( ; !q.empty(); ) {
					int cost = q.top().first;
					int id = q.top().second.first;
					int pass = q.top().second.second;
					
					q.pop();
					
					if (pass > K || dp2[id][pass] < cost) continue;
					
					if (id == N - 1) {
						ans.first = cost;
						break;
					}
					
					for (int i = 0; i < (int) graph[id].size(); i++) {
						int next = graph[id][i].first;
						int ec = graph[id][i].second;
						
						if (dp2[next][pass + 1] > dp2[id][pass] + ec) {
							dp2[next][pass + 1] = dp2[id][pass] + ec;
							q.push(make_pair(dp2[id][pass] + ec, make_pair(next, pass + 1)));
						}
					}
				}
				
			}					
		}
		cout << ans.first << "\n";
		/*
		memset(dp, -1LL, sizeof(dp));

		
		Int ans = func(0, 1);

		if (ans == -1LL || ans >= INF) ans = -1;

		cout << ans << "\n";
		*/
	}
    return 0;
}
