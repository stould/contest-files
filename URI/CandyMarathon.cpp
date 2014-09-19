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

const int MAXN = 10004;

int T, N, M;
vector<int> graph[MAXN];
int vis[MAXN];

int main(void) {
	scanf("%d", &T);

	for ( ; T--; ) {
		scanf("%d%d", &N, &M);

		for (int i = 0; i <= N; i++) {
			vis[i] = 0;
			graph[i].clear();
		}

		for (int i = 0; i < M; i++) {
			int A, B;
			scanf("%d%d", &A, &B);

			graph[A].push_back(B);
			graph[B].push_back(A);
		}

		bool ok = true;

		for (int i = 0; i < N; i++) {
			ok &= (graph[i].size() % 2 == 0);
		}
		
		if (ok) {
			puts("Yes");
		} else {
			puts("No");
		}
	}

    return 0;
}
