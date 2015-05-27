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

const int MAXN = 555;
const int MAXL = 601*481 + 10;
const int INF = 10101011;

int N, M;
vector<int> graph[MAXN];
vector<pair<pair<int, int>, int> > info[MAXN][MAXN];
int dist[MAXL];
int stim[MAXL];

struct state {
	int id, charge, daytime;
	int code;
	
	state(){}

	state(int id, int charge, int daytime): id(id), charge(charge), daytime(daytime) {
		this->code = this->id * 481 + this->charge;
	}
	
	bool operator<(const state other) const {
		return dist[code] > dist[other.code];
	}
};

/*
  Exemplo 1: (0 - 1) => 100
             (1 - 3) => 75 + (5 min de espera)

			 
			Exemplo (570) : (0 - 1) => 200
			              : (1 - 3) => 570 (300)
 */

int main(void) {
	while (cin >> N >> M && !(N == 0 && M == 0)) {
		int A, B, X, Y, Z;
		
		for (int i = 0; i < MAXN; i++) {
			graph[i].clear();
			for (int j = 0; j < MAXN; j++) {
				info[i][j].clear();
			}
		}
		for (int i = 0; i < M; i++) {
			cin >> A >> B;
			graph[A].push_back(B);
			graph[B].push_back(A);

			while (1) {
				cin >> X >> Y >> Z;
				
				if (Z <= 280) {
					info[A][B].push_back(make_pair(make_pair(X, Y), Z));
					info[B][A].push_back(make_pair(make_pair(X, Y), Z));
				}				
				if (Y == 1439) break;
			}
		}

		int ans = INF;
		priority_queue<state> q;
		state base = state(0, 480, 720);

		q.push(base);
		
		memset(dist, 63, sizeof(dist));
		memset(stim, 63, sizeof(stim));
		
		dist[base.code] = 0;
		stim[base.code] = 0;
		
		for ( ; !q.empty(); ) {
			state now = q.top();
			q.pop();

			if (dist[now.code] > ans) continue;
			
			//cout << now.id << " " << now.charge << " " << now.daytime << " => " << dist[now.id][now.daytime] << "\n";
			
			if (now.id == N - 1) {
				chmin(ans, dist[now.code]);
			}
			
			for (int i = 0; i < (int) graph[now.id].size(); i++) {
				int next = graph[now.id][i];
				
				for (int k = 0; k < (int) info[now.id][next].size(); k++) {
					int si = info[now.id][next][k].first.first;
					int ed = info[now.id][next][k].first.second;
					int tt = info[now.id][next][k].second * 2;
					
					int wait_time = max(0, tt - now.charge);
					int next_daytime = (stim[now.code] + wait_time) % 1440;
					
					if (next_daytime > ed) {
						wait_time += 1440 - next_daytime + si;
						next_daytime = si;
					} else if (next_daytime < si) {
						wait_time += si - next_daytime;
						next_daytime = si;
					}

					next_daytime = (next_daytime + tt / 2) % 1440;
					
					int fuel_next = min(480, wait_time + now.charge) - tt;
					int next_dist = dist[now.code] + wait_time + tt / 2;

					state next_state = state(next, fuel_next, next_daytime);
					
					if (dist[next_state.code] > next_dist) {
						dist[next_state.code] = next_dist;
						stim[next_state.code] = next_daytime;
						//cout << "Go: " << now.id << " to: " << next << " <=> wait: " << wait_time << " peso " << tt / 2 << " - fuel_next: " << fuel_next << " dt = " << dist[next][next_daytime] << " time: " << next_daytime << "\n";
						q.push(next_state);
					}
				}
			}						
		}
		cout << ans << "\n";
	}
	return 0;
}
