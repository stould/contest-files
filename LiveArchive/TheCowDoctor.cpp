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

const int MAXN = 600;

int N, M;
bool mark[MAXN][MAXN];
bool contains[MAXN][MAXN];

int main(void) {
	for ( ; cin >> N >> M && N + M != 0; ) {
		memset(mark, false, sizeof(mark));
		memset(contains, false, sizeof(contains));
		
		for (int i = 0; i < M; i++) {
			int K, P;
			cin >> K;

			for (int j = 0; j < K; j++) {
				cin >> P;

				mark[i][P - 1] = true;
			}
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				bool is_sub = true;
				
				for (int k = 0; k < N; k++) {					
					if ((mark[j][k] && !mark[i][k])) {
						is_sub = false;
						break;
					}
				}
				contains[i][j] = is_sub;
			}
		}

		int ans = 0;
		
		for (int i = 0; i < M; i++) {
			vector<bool> seen(N, false);
			
			for (int j = 0; j < M; j++) {
				if (i != j && contains[i][j]) {
					for (int k = 0; k < N; k++) {				
						if (mark[j][k]) {
							seen[k] = true;
						}
					}
				}
			}
			
			bool ok = true;
			
			for (int j = 0; j < N; j++) {
				if (mark[i][j]) {
					if (!seen[j]) {
						ok = false;
					}
				}
			}
			if (ok) {
				ans += 1;
			}
		}
		if (ans == M) {
			ans -= 1;
		}
		
		cout << ans << endl;
	}
	return 0;
}
