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
const int MAXN = 110;

int T, N;
int Qt[MAXN], P[MAXN];

pair<int, pair<int, int> > dp[MAXN][55];

pair<int, pair<int, int> > func(int id, int w) {
	if (id == N) {
		return make_pair(0, make_pair(0, 0));
	} else {
		pair<int, pair<int, int> >& ans = dp[id][w];

		if (ans.first == -1) {
			ans = func(id + 1, w);

			if (w + P[id] <= 50) {				
				pair<int, pair<int, int> > next = func(id + 1, w + P[id]);

				next.first += Qt[id];
				next.second.first += P[id];
				next.second.second += 1;
				
				if (next.first > ans.first) {
					ans = next;
				}
			}								  
		}

		return ans;
	}
}

int main(void) {
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> Qt[i] >> P[i];
		}

		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= 50; j++) {
				dp[i][j] = make_pair(-1, make_pair(-1, -1));
			}
		}
				
		pair<int, pair<int, int> > ans = func(0, 0);

		cout << ans.first << " brinquedos\n" << "Peso: " << ans.second.first << " kg\n" << "sobra(m) " << N - ans.second.second << " pacote(s)\n\n";
	}
    return 0;
}
