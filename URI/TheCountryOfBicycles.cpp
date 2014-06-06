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
const int INF = INT_MAX / 3;
const int SHOLD = 10000;

int N, M, K;
int D[MAXN], vis[MAXN];
vector<pair<int, int> >  graph[MAXN];

struct MyCmp {
	bool operator()(int a, int b) {
		return D[a] > D[b];
	}
};

int func(int f, int t, int sp) {
	priority_queue<int, vector<int>, MyCmp> q;
	q.push(f);

	fill(vis, vis + N + 1, -INF);	
	fill(D, D + N + 1, INF);

	D[f] = 0;

	for ( ; !q.empty(); ) {
		int now = q.top();
		q.pop();

		if (now == t) {
			continue;
		}

		for (int i = 0; i < (int) graph[now].size(); i++) {
			int u = graph[now][i].first;
			int u_height = graph[now][i].second;

			if (D[u] >= D[now] + u_height && u_height <= sp) {				
				D[u] = D[now] + u_height;
				vis[u] = max(vis[u], max(vis[now], u_height));
				q.push(u);
			}
		}
	}
	return vis[t] != (-INF);
}


int main(void) {
	int test = 1;
	int A, B, C;
	for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
		for (int i = 0; i < MAXN; i++) {
			graph[i].clear();
		}
		for (int i = 0; i < M; i++) {
			scanf("%d%d%d", &A, &B, &C);
			graph[A].push_back(make_pair(B, C + SHOLD));
			graph[B].push_back(make_pair(A, C + SHOLD));
		}

		scanf("%d", &K);
		printf("Instancia %d\n", test++);
		for ( ; K--; ) {
			scanf("%d%d", &A, &B);		

			int l = -1000, h = 1000, m;
			int ans = 0;

			for ( ; l <= h; ) {
				m = (l + h) / 2;

				bool tmp = func(A, B, m + SHOLD);

				if (tmp) {
					ans = m;
					h = m - 1;
				} else {
					l = m + 1;
				}
			}
			printf("%d\n", ans);
		}
		printf("\n");
	}
    return 0;
}
