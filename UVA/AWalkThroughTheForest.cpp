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
const int INF = INT_MAX / 4;

int N, M;
vector<pair<int, int> > G[MAXN];
int dist[MAXN], cnt[MAXN];

int main(void) {
	while (cin >> N >> M) {
		if (N == 0) break;

		int A, B, C;

		for (int i = 0; i <= N; i++) {
			dist[i] = INF;
			cnt[i] = 0;
			G[i].clear();
		}
		
		for (int i = 0; i < M; i++) {
			cin >> A >> B >> C;
			G[A].push_back(make_pair(B, C));
			G[B].push_back(make_pair(A, C));
		}

		priority_queue<pair<int, int> > q;
		q.push(make_pair(0, 1));

		dist[1] = 0;
		cnt[1] = 1;

		for ( ; !q.empty(); ) {
			int cost = -q.top().first;
			int curr = q.top().second;

			q.pop();

			//cout << curr << " " << cnt[curr] << endl;
			if (cost > dist[curr]) continue;

			for (int i = 0; i < (int) G[curr].size(); i++) {
				int next = G[curr][i].first;
				int len  = G[curr][i].second;

				if (dist[next] > dist[curr] + len) {
					dist[next] = dist[curr] + len;
					cnt[next] = cnt[curr];
					q.push(make_pair(-dist[next], next));
				} else if (dist[next] == dist[curr] + len) {
					cnt[next] += cnt[curr];
				}				
			}
		}
		
		cout << cnt[2] << "\n";
	}
	return 0;
}
