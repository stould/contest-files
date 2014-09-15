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

const int INF = INT_MAX / 3;

int N;
int dist[110][110];
string S[110];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};


int main(void) {
	for ( ; cin >> N; ) {
		for (int i = 0; i < N; i++) {
			cin >> S[i];
		}

		int ans = INF;

		for (int mask = 0; mask < (1 << 10) - 1; mask++) {
			if (isupper(S[0][0]) && !(mask & (1 << (S[0][0] - 'A')))) {
				continue;
			}
			if (islower(S[0][0]) &&  (mask & (1 << (S[0][0] - 'a')))) {
				continue;
			}

			queue<pair<int, int> > q;
			q.push(make_pair(0, 0));

			for (int i = 0; i <= N; i++) {
				fill(dist[i], dist[i] + N, INF);
			}

			dist[0][0] = 0;

			for ( ; !q.empty(); ) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				
				for (int i = 0; i < 4; i++) {
					int px = x + dx[i];
					int py = y + dy[i];

					if (px >= 0 && py >= 0 && px < N && py < N) {
						if (isupper(S[px][py]) && (mask & (1 << (S[px][py] - 'A')))) {
							if (dist[px][py] > dist[x][y] + 1) {
								dist[px][py] = dist[x][y] + 1;
								q.push(make_pair(px, py));
							}
						}
						if (islower(S[px][py]) && !(mask & (1 << (S[px][py] - 'a')))) {
							if (dist[px][py] > dist[x][y] + 1) {
								dist[px][py] = dist[x][y] + 1;
								q.push(make_pair(px, py));
							}
						}
					}
				}
			}
			chmin(ans, dist[N-1][N-1]);
		}
		if (ans + 1 >= INF) {
			ans = -1;
		} else {
			ans += 1;
		}
		cout << ans << "\n";
	}
    return 0;
}
