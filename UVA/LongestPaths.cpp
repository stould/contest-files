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

const int MAXN = 110;
const int INF = 10010100;

int N;
int dist[MAXN];

int S;

vector<int> graph[MAXN];

int main(void) {
	int i;
	int A, B;

	int test = 1;

	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		S = in();

		for (i = 0; i < MAXN; i++) {
			graph[i].clear();
			dist[i] = -INF;
		}

		for ( ; scanf("%d%d", &A, &B) == 2 && A + B != 0; ) {
			graph[A].push_back(B);
		}

		queue<int> q; q.push(S);

		dist[S] = 0;

		int len = 0;
		int id = 0;

		for ( ; !q.empty(); ) {
			int now = q.front(); q.pop();

			for (i = 0; i < (int) graph[now].size(); i++) {
				int u = graph[now][i];

				if (dist[now] + 1 > dist[u]) {
					dist[u] = dist[now] + 1;
					q.push(u);

					if (dist[u] > len || (dist[u] == len && u < id)) {
						len = dist[u];
						id = u;
					}
				}
			}
		}

		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", test++, S, len, id);
	}
    return 0;
}
