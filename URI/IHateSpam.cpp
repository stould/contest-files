#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cstdlib>


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

const int MAXN = 22;

int N;
int A, T[105][3], deg[MAXN];
char spam[105][3][50], buff[105];
vector<int> graph[MAXN];
vector<int> vis[MAXN];
bool vis_now[MAXN];

void bfs(int x, int id) {
	queue<int> q;
	q.push(x);
	vis[x].push_back(id);

	memset(vis_now, false, sizeof(vis_now));
	vis_now[x] = true;

	for ( ; !q.empty(); ) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < (int) graph[now].size(); i++) {
			int u = graph[now][i];

			if (!vis_now[u]) {
				q.push(u);
				vis[u].push_back(id);
				vis_now[u] = true;
			}
		}
	}
}

int main(void) {
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		for (int i = 0; i < MAXN; i++) {
			vis_now[i] = deg[i] = 0;
			graph[i].clear();
			vis[i].clear();
		}
		for (int i = 1; i <= N; i++) {
			int c;
			for ( ; scanf("%d", &A) && A != 0; ) {
				graph[i].push_back(A);
				deg[i] += 1;
			}
		}
		int sp = 1;
		for ( ; scanf("%d", &A) && A != 0; ) {
			T[sp][0] = A;
			scanf("%d%d", &T[sp][1], &T[sp][2]);
			scanf("%s%s%s", spam[sp][0], spam[sp][1], spam[sp][2]);
			bfs(T[sp][0], sp);
			sp += 1;			
		}

		for (int i = 1; i <= N; i++) {
			scanf("%s", buff);
			printf("%s: ", buff);
			for (int j = 1; j < sp; j++) {
				int u = j;
				
				int cnt = 0;

				if (find(vis[i].begin(), vis[i].end(), j) != vis[i].end()) {
					cnt = deg[i];
				}

				if (cnt < T[u][1]) {
					printf("%s ", spam[u][0]);
				} else if (cnt >= T[u][1] && cnt < T[u][2]) {
					printf("%s ", spam[u][1]);
				} else {
					printf("%s ", spam[u][2]);
				}
			}
			printf("\n");
		}
	}
    return 0;
}
