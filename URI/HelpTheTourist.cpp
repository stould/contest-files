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

const int MAXN = 1010;
const int INF = INT_MAX / 4;

int T, N, M, K;
int NX[MAXN], NY[MAXN], MX[MAXN], MY[MAXN];
int main(void) {
	scanf("%d", &T);

	for ( ; T--; ) {
		scanf("%d%d%d", &N, &M, &K);

		for (int i = 1; i <= N; i++) {
			scanf("%d%d", &NX[i], &NY[i]);
		}

		vector<int> ds;
		
		for (int i = 1; i <= M; i++) {
			scanf("%d%d", &MX[i], &MY[i]);

			for (int j = 1; j <= N; j++) {
				int dst = abs(MX[i] - NX[j]) + abs(MY[i] - NY[j]);
				ds.push_back(dst);
			}
		}
		
		//long long ans = mcmf(s, t, K);
		sort(ds.begin(), ds.end());
		long long ans = 0;
		for (int i = 0; i < K; i++) ans += ds[i];
		
		printf("%lld\n",  ans);
	}
    return 0;
}
