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

const int MAXN = 110;
const int INF = INT_MAX / 5;

int T, N, M;
int dst[MAXN][MAXN];

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M;

		for (int i = 0; i < MAXN; i++) {
			fill(dst[i], dst[i] + MAXN, INF);
			dst[i][i] = 0;
		}

		for (int i = 0; i < M; i++) {
			int A, B, C;
			cin >> A >> B >> C;

			dst[A][B] = min(dst[A][B], C);
			dst[B][A] = min(dst[B][A], C);
		}

		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
				}
			}
		}

					
		int best = INF;
		
		for (int i = 1; i <= N; i++) {
			set<int> cnt;

			for (int j = 1; j <= 5; j++) {
				cnt.insert(dst[i][j]);
			}

			if (cnt.size() == 1) {
				int curr_m = -INF;
				
				for (int j = 1; j <= N; j++) {
					chmax(curr_m, dst[i][j]);
				}

				if (curr_m < best) {
					best = curr_m;
				}
			}
		}

		if (best == INF) {
			best = -1;
		}
		cout << "Map " << t << ": " << best << "\n";
	}
	return 0;
}
