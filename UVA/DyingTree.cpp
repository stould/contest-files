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

const int MAXN = 500;

int T, N, M, K, D;
int TI_C[MAXN];
pair<int, int> DI[MAXN], TI[MAXN][MAXN];
vector<int> G[MAXN];
bool vis[MAXN];

int dist(int x, int y) {
	return x * x + y * y;
}

void dfs(int x) {
	vis[x] = true;

	for (int i = 0; i < (int) G[x].size(); i++) {
		int u = G[x][i];

		if (!vis[u]) {
			dfs(u);
		}		
	}
}

int main(void) {
	cin >> T;

	for ( ; T--; ) {
		cin >> N >> M >> K >> D;

		D *= D;
		K *= K;
		
		for (int i = 0; i < MAXN; i++) {
			vis[i] = false;
			G[i].clear();
		}
		
		for (int i = 0; i < M; i++) {
			cin >> DI[i].first >> DI[i].second;
		}

		for (int i = 0; i < N; i++) {
			cin >> TI_C[i];

			for (int j = 0; j < TI_C[i]; j++) {
				cin >> TI[i][j].first >> TI[i][j].second;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				bool found = false;
				
				for (int k = 0; !found && k < TI_C[i]; k++) {
					for (int l = 0; !found && l < TI_C[j]; l++) {
						int dst = dist(TI[i][k].first - TI[j][l].first, TI[i][k].second - TI[j][l].second);
						
						if (dst <= K) {
							G[i].push_back(j);
							G[j].push_back(i);
							found = true;
						}	
					}
				}
			}
			for (int j = 0; j < M; j++) {
				for (int k = 0; k < TI_C[i]; k++) {
					int dst = dist(TI[i][k].first - DI[j].first, TI[i][k].second - DI[j].second);
					
					if (dst <= D) {
						G[i].push_back(N + j);
						G[N + j].push_back(i);
					}
				}
			}
		}

		dfs(0);
		
		bool ans = false;

		for (int i = N; i < N + M; i++) {
			if (vis[i]) {
				ans = true;
				break;				   
			}
		}
		
		if (ans) {
			cout << "Tree can be saved :)\n";
		} else {
			cout << "Tree can't be saved :(\n";
		}
	}
	return 0;
}
