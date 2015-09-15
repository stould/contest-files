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

const int MAXN = 4010;
const int INF = 100101010;

int N, M;
vector<int> graph[MAXN];
int mat[MAXN][MAXN];
int deg[MAXN];

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;

		graph[A].push_back(B);
		graph[B].push_back(A);

		mat[A][B] = mat[B][A] = 1;

		deg[A] += 1;
		deg[B] += 1;
	}

	int ans = INF;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < (int) graph[i].size(); j++) {
			for (int k = j + 1; k < (int) graph[i].size(); k++) {
				int ai = i;
				int aj = graph[i][j];
				int ak = graph[i][k];

				if (mat[aj][ak]) {
					int sum = (deg[ai] - 2) + (deg[aj] - 2) + (deg[ak] - 2);

					ans = min(ans, sum);
				}
			}
		}
	}
	if (ans == INF) ans = -1;
	
	cout << ans << "\n";
	return 0;
}
