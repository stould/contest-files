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

const int MAXN = 1003;

int T, N, M;
string S[MAXN];
int seen_fire[MAXN][MAXN];
int dist[MAXN][MAXN];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int fire_bfs(int si, int sj) {
	queue<pair<int, int> > q;
	q.push(make_pair(si, sj));

	seen_fire[si][sj] = 0;

	int ans = INT_MAX;
	
	while (!q.empty()) {
		int now_i = q.front().first;
		int now_j = q.front().second;
		q.pop();

		if (S[now_i][now_j] == 'F') {
			chmin(ans, seen_fire[now_i][now_j]);
		}
		
		for (int i = 0; i < 4; i++) {
			int next_i = now_i + dx[i];
			int next_j = now_j + dy[i];

			if (next_i >= 0 && next_i < N && next_j >= 0 && next_j < M) {
				if (S[next_i][next_j] == '#') continue;
				if (seen_fire[next_i][next_j] > seen_fire[now_i][now_j] + 1) {
					seen_fire[next_i][next_j] = seen_fire[now_i][now_j] + 1;
					q.push(make_pair(next_i, next_j));
				}
			}
		}
	}

	return ans;
}

int can_bfs(int si, int sj, int ei, int ej) {
	queue<pair<int, int> > q;
	q.push(make_pair(si, sj));

	dist[si][sj] = 0;
	
	while (!q.empty()) {
		int now_i = q.front().first;
		int now_j = q.front().second;
		q.pop();

		//cout << now_i << " " << now_j << " "<< dist[now_i][now_j] << " " << seen_fire[now_i][now_j] << "\n";
		
		for (int i = 0; i < 4; i++) {
			int next_i = now_i + dx[i];
			int next_j = now_j + dy[i];

			if (next_i >= 0 && next_i < N && next_j >= 0 && next_j < M) {
				if (seen_fire[next_i][next_j] <= dist[now_i][now_j] + 1) continue;
				
				if (dist[next_i][next_j] > dist[now_i][now_j] + 1) {
					dist[next_i][next_j] = dist[now_i][now_j] + 1;
					q.push(make_pair(next_i, next_j));
				}
			}
		}
	}
	return dist[ei][ej];;
}

int main(void) {
	cin >> T;

	for ( ; T--; ) {
		cin >> N >> M;

		memset(seen_fire, 63, sizeof(seen_fire));
		memset(dist, 63, sizeof(dist));

		int si = -1, sj = -1;
		int ei = -1, ej = -1;

		for (int i = 0; i < N; i++) {
			cin >> S[i];

			for (int j = 0; j < M; j++) {
				if (S[i][j] == 'S') {
					si = i;
					sj = j;
				} else if (S[i][j] == 'E') {
					ei = i;
					ej = j;
				}				
			}			
		}

		int path_dist = can_bfs(si, sj, ei, ej);
		int best_fire = fire_bfs(ei, ej);
		
		if (path_dist < best_fire) {
			cout << "Y\n";
		} else {
			cout << "N\n";
		}
	}
	return 0;
}
