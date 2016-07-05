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

const int MAXN = 105;

int dx[24] = { 1, 2, -1, -2, 1, 2, -1, -2, 1, 2, -1, -2, 1, 2, -1, -2, 0, 0, 0, 0, 0, 0, 0, 0 };
int dy[24] = { 2, 1, 2, 1, -2, -1, -2, -1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 2, 1, -2, -1, -2, -1 };
int dz[24] = { 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 2, 1, -2, -1, -2, -1, 1, 2, -1, -2, 1, 2, -1, -2 };

int N, M, L;
int P[5][5];
int dist[MAXN][MAXN][MAXN];

bool in(int i, int j, int k) {
	return i >= 1 && i <= N && j >= 1 && j <= M && k >= 1 && k <= L;
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> L;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> P[i][j];
		}
	}

	queue<pair<int, pair<int, int> > > q[24];	
	q[0].push(make_pair(P[0][0], make_pair(P[0][1], P[0][2])));

	memset(dist, 63, sizeof(dist));

	dist[P[0][0]][P[0][1]][P[0][2]] = 0;
	
	int ans = INT_MAX;
	bool end = false;
	
	for ( ; !end ; ) {
		bool seen = false;
		
		for (int i = 0; !end && i < 24; i++) {
			if (!q[i].empty()) {
				seen = true;
				
				int ci = q[i].front().first;
				int cj = q[i].front().second.first;
				int ck = q[i].front().second.second;
				q[i].pop();

				if (ci == P[1][0] && cj == P[1][1] && ck == P[1][2]) {
					ans = min(ans, dist[ci][cj][ck]);
					end = true;
					break;
				}

				for (int j = 0; j < 24; j++) {
					int ni = ci + dx[j];
					int nj = cj + dy[j];
					int nk = ck + dz[j];

					if (in(ni, nj, nk) && dist[ni][nj][nk] > dist[ci][cj][ck] + 1) {
						dist[ni][nj][nk] = dist[ci][cj][ck] + 1;
						q[i].push(make_pair(ni, make_pair(nj, nk)));					
					}
				}
			}
		}
		if (!seen) break;
	}

	cout << ans << endl;
	
	return 0;
}
