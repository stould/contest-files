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

const int MAXN = 1010;
const int INF = INT_MAX / 5;

int N, M, Q;
vector<pair<int, int> > G[MAXN];
int P[MAXN];
int dst[MAXN][120];

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;

		G[A].push_back(make_pair(B, C));
		G[B].push_back(make_pair(A, C));
	}

	cin >> Q;

	for ( ; Q--; ) {
		int C, S, E;
		cin >> C >> S >> E;

		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= C; j++) {
				dst[i][j] = INF;
			}
		}
		
		priority_queue<pair<int, pair<int, int> > > q;
		

		q.push(make_pair(0, make_pair(0, S)));
		dst[S][0] = 0;

		int best = INF;   

		for ( ; !q.empty(); ) {
			int cst = -q.top().first;
			int gas = q.top().second.first;
			int index = q.top().second.second;
			q.pop();

			if (cst > dst[index][gas]) {
				continue;
			}

			if (index == E) {
				chmin(best, cst);
				break;
			}

			for (int i = 0; i < (int) G[index].size(); i++) {
				int u = G[index][i].first;
				int len = G[index][i].second;

				for (int j = 0; gas + j <= C; j++) {
					int new_cost = cst + (P[index] * j);
					int new_gas = gas + j - len;

					if (new_gas >= 0) {
						if (dst[u][new_gas] > new_cost) {
							dst[u][new_gas] = new_cost;

							q.push(make_pair(-new_cost, make_pair(new_gas, u)));
						}
					}					
				}
			}
		}

		if (best == INF) {
			cout << "impossible\n";
		} else {
			cout << best << "\n";
		}
		
	}
	
	return 0;
}
