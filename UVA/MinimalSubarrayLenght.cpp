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

const int MAXN = 500004;
const int INF = INT_MAX / 3;

int T, N, X;
Int P[MAXN], S[MAXN];

int main(void) {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d", &N, &X);
		S[0] = 0;
		for (int i = 1; i <= N; i++) {
			scanf("%lld", &P[i]);
			S[i] = S[i - 1] + P[i];
		}

		int ans = INF;
		priority_queue<pair<Int, int>, vector<pair<Int, int> >, greater<pair<Int, int> > > q;
		
		q.push(make_pair(S[0], 0));

		for (int i = 1; i <= N; i++) {
			while (!q.empty() && S[i] - q.top().first >= X) {
				chmin(ans, i - q.top().second);
				q.pop();
			}
			q.push(make_pair(S[i], i));
		}

		if (ans == INF) {
			ans = -1;
		}

		printf("%d\n", ans);
	}
    return 0;
}
