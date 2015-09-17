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
typedef unsigned uint;

const int MAXN = 30005;
const int INF = INT_MAX / 4;

int T, N, M;
int P[MAXN];
vector<pair<int, int> > graph[MAXN];
int profit[MAXN];
int pr[MAXN];

int main(void) {
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N >> M;

		for (int i = 0; i < MAXN; i++) {
			graph[i].clear();
			profit[i] = -INF;
		}

		for (int i = 1; i <= N; i++) {
			cin >> P[i];
		}

		for (int i = 0; i < M; i++) {
			int A, B, C;
			cin >> A >> B >> C;

			graph[A].push_back(make_pair(B, C));
		}

		queue<int> q;
		q.push(1);

		pr[1] = 1;
		profit[1] = P[1];
		
		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int i = 0; i < (int) graph[now].size(); i++) {
				int u = graph[now][i].first;
				int cst = graph[now][i].second;

				int next_val = profit[now] + P[u] - cst;

				if (profit[u] < next_val) {
					profit[u] = next_val;
					pr[u] = now;
					q.push(u);
				}
			}
		}

		int best = -1, id = 0;
		
		for (int i = 1; i <= N; i++) {
			if (profit[i] > best) {
				best = profit[i];
				id = i;
			}
		}

		vector<int> path;
		path.push_back(id);

		while (pr[id] != id) {
			id = pr[id];
			path.push_back(id);
		}

		reverse(path.begin(), path.end());

		cout << best << " " << path.size() << "\n";

		for (int i = 0; i < (int) path.size(); i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
