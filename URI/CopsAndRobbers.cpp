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

int T;
int P[5][5];
int dp[5][5];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main(void) {
	cin >> T;

	while (T--) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> P[i][j];
				dp[i][j] = 0;
			}
		}

		queue<pair<int, int> > q;

		if (P[0][0] == 0) {			
			q.push(make_pair(0, 0));
			dp[0][0] = 1;
		}

		while (!q.empty()) {
			int pi = q.front().first;
			int pj = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int di = pi + dx[i];
				int dj = pj + dy[i];

				if (di >= 0 && dj >= 0 && di < 5 && dj < 5 && P[di][dj] == 0) {
					if (!dp[di][dj]) {
						dp[di][dj] = 1;
						q.push(make_pair(di, dj));
					}
				}
			}
		}

		if (dp[4][4]) {
			cout << "COPS\n";
		} else {
			cout << "ROBBERS\n";
		}
	}
	return 0;
}
