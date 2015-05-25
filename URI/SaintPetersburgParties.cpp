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

int N, M, K;
vector<int> G[MAXN];
int deg[MAXN];

int main(void) {
	while (cin >> N >> M >> K) {
		for (int i = 0; i < MAXN; i++) {
			G[i].clear();
			deg[i] = 0;
		}
		for (int i = 0; i < M; i++) {
			cin >> A >> B;
			deg[A] += 1;
			deg[B] += 1;
			G[A].push_back(B);
			G[B].push_back(A);
		}
		sort(P, P + N, cmp);

		for (int i = 0; i < N; i++) {
			if (deg[i] < K) {
				for (int j = 0; j < (int) G[i].size(); j++) {
					deg[G[i][j]] -= 1;
				}
			}
		}
		
	}
	return 0;
}
