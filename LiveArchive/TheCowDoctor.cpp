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

const int MAXN = 310;

int N, M;
bool contain[MAXN][MAXN];
bool mark[MAXN][MAXN];
bool vis[MAXN];

int main(void) {
	for ( ; cin >> N >> M && N + M != 0; ) {
		memset(contain, false, sizeof(contain));
		memset(mark, false, sizeof(mark));
		
		for (int i = 0; i < M; i++) {
			int K, P;
			cin >> K;

			for (int j = 0; j < K; j++) {
				cin >> P;

				mark[i][P - 1] = true;
			}
		}

		int ans = 0;
		
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				if (i == j) continue;
				
				contain[i][j] = true;
				
				for (int k = 0; k < N; k++) {
					if (!mark[i][k] && mark[j][k]) contain[i][j] = false;
				}
			}			
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (mark[i][j]) {
					bool ok = true;

					for (int k = 0; k < M; k++) {
						if (i != k && !vis[k] && contain[i][k] && mark[k][j]) {
							ok = false;
						}
					}

					if (!ok) {
						vis[i] = false;						
						ans += 1;
						break;
					}
				}
			}
		}

		cout << ans << endl;
	}
	return 0;
}
