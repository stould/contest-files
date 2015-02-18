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

const int MAXN = 10005;
const int MOD = 10000;
const int INF = INT_MAX / 3;

int U, L, R;
int P[12];
int dist[MAXN];

int main(void) {
	int t = 1;
	for ( ; scanf("%d%d%d", &U, &L, &R) == 3 && U + L + R != 0; ) {
		for (int i = 0; i < R; i++) {
			scanf("%d", &P[i]);
		}
		for (int i = 0; i <= MOD; i++) {
			dist[i] = INF;
		}
		
		dist[U] = 0;

		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

		q.push(make_pair(0, U));

		for ( ; !q.empty(); ) {
			int d = q.top().first;
			int id = q.top().second;
			q.pop();

			if (d > dist[id]) break;

			for (int i = 0; i < R; i++) {
				int next = (id + P[i]) % MOD;

				if (d + 1 < dist[next]) {
					dist[next] = d + 1;
					q.push(make_pair(d + 1, next));
				}
			}				
		}
		
		printf("Case %d: ", t++);

		if (dist[L] == INF) {
			puts("Permanently Locked");
		} else {
			printf("%d\n", dist[L]);
		}
	}
    return 0;
}
