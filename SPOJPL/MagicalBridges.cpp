#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>
#include <cstdio>

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

const int MAXN = 310;
const int INF = INT_MAX / 3;

int T, N, M, F, S, Q;
int dist[MAXN][MAXN];
vector<int> B[MAXN];

int id;
map<pair<int, int>, int> memo;

void add_edge(int i, int j, int cost) {
	dist[i][i] = dist[j][j] = 0;

	dist[i][j] = min(dist[i][j], cost);
	dist[j][i] = min(dist[j][i], cost);
}

int prep(int i, int j) {
	pair<int, int> rp = make_pair(i, j);

	if (memo[rp] == 0) {
		memo[rp] = id++;
	}

	return memo[rp];
}

int query(int bi, int fi, int bj, int fj) {
	int ans = dist[prep(bi, 1)][prep(bj, 1)] + (fi - 1) + (fj - 1);

	for (int i = 0; i < (int) B[bi].size(); i++) {
		for (int j = 0; j < (int) B[bj].size(); j++) {
			int floori = B[bi][i];
			int floorj = B[bj][j];

			int curr_ans = dist[prep(bi, floori)][prep(bj, floorj)] + abs(fi - floori) + abs(fj - floorj);

			ans = min(ans, curr_ans);
		}
	}

	if (bi == bj) {
		ans = min(ans, abs(fi - fj));
	}

	return ans;
}

int main(void) {
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		memo.clear();
		id = 1;

		for (int i = 0; i < MAXN; i++) {
			B[i].clear();
			fill(dist[i], dist[i] + MAXN, INF);
		}

		scanf("%d%d%d", &N, &F, &M);
		
		int Bi, Fi, Bj, Fj;

		for (int i = 1; i <= N; i++) {
			B[i].push_back(1);

			for (int j = i + 1; j <= N; j++) {
				if (i != j) {
					add_edge(prep(i, 1), prep(j, 1), min(j - i, i + (N - j)));
				}
			}
		}

		
		for (int i = 0; i < M; i++) {
			scanf("%d%d%d%d%d", &Bi, &Fi, &Bj, &Fj, &S);
			B[Bi].push_back(Fi);
			B[Bj].push_back(Fj);
			
			add_edge(prep(Bi, Fi), prep(Bj, Fj), S);
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < B[i].size(); j++) {
				for (int k = 0; k < B[i].size(); k++) {
					add_edge(prep(i, B[i][j]), prep(i, B[i][k]), abs(B[i][j] - B[i][k]));
				}
			}
		}

		for (int k = 1; k < MAXN; k++) {
			for (int i = 1; i < MAXN; i++) {
				for (int j = 1; j < MAXN; j++) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		cin >> Q;

		for (int i = 0; i < Q; i++) {
			scanf("%d%d%d%d", &Bi, &Fi, &Bj, &Fj);
			cout << query(Bi, Fi, Bj, Fj) << "\n";
		}
	}
    return 0;
}
