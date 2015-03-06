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

const int MAXN = 100;

int N, M;
vector<pair<int, int> > graph[MAXN];

int main(void) {
	for ( ; scanf("%d%d", &N, &M) == 2; ) {
		int A, B, C;
		
		for (int i = 0; i < M; i++) {
			scanf("%d%d%d", &A, &B, &C);
			graph[A].push_back(make_pair(B, C));
			graph[B].push_back(make_pair(A, C));
		}

		int ans = 0;
		
		priority_queue<pair<int, int> > q;
		set<int> seen;
		
		q.push(make_pair(0, 1));

		for ( ; !q.empty(); ) {
			int now = q.top().second;
			int cst = -q.top().first;
			q.pop();

			if (seen.count(now)) continue;

			seen.insert(now);
			ans += cst;
		
			for (int i = 0; i < (int) graph[now].size(); i++) {
				q.push(make_pair(-graph[now][i].second, graph[now][i].first));
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}
