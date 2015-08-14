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
typedef unsigned uint;

const int MAXN = 500005;

int N, M;
string S;
int P[MAXN];
vector<int> tree[MAXN];
int cnt[MAXN][30];

void uptree(int node) {
	if (node == -1) return;

	for (int i = 0; i < 30; i++) {
		cnt[P[node]][i] += cnt[node][i];
	}
	
	uptree(P[node]);
}

int main(void) {
	cin >> N >> M;

	P[1] = -1;
	
	for (int i = 2; i <= N; i++) {
		cin >> P[i];
		tree[P[i]].push_back(i);
	}

	for (int i = 1; i <= N; i++) {
		if (tree[i].empty()) {
			uptree(i);
		}
	}

	for (int i = 0; i < M; i++) {
		
	}
	
	return 0;
}
