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

const int MAXN = 110;
int T, N, M;
int P[MAXN], Q[MAXN];

vector<int> graph[MAXN];

bool try_kuhn(int v) {
	if (used[v]) {
		return false;
	}
	used[v] = true;
	for (int i = 0; i< (int) graph[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || try_kuhn(mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> P[i];
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> Q[i];
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				
			}
		}
	}
    return 0;
}
