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

const int MAXN = 100005;

int N, K, Q, X, Y;
int pt[MAXN];

int id[MAXN];
int sz[MAXN];

void build(void) {
	for (int i = 1; i <= N; i++) {
		id[i] = i;
		sz[i] = 1;
	}
}

int root(int i) {
	while(i != id[i]) {
		id[i] = id[id[i]];
		i = id[i];
	}
	return i;
}

int sum(int p, int q) {
	int ps = pt[root(p)];
	int pq = pt[root(q)];

	if (ps > pq && root(p) == 1) {
		return 1;
	} else if (ps < pq && root(q) == 1) {
		return 1;
	} else {
		return 0;
	}
}

bool find(int p, int q) {
	return root(p) == root(q);
}
void unite(int p, int q) {
	int i = root(p);
	int j = root(q);

	if(i == j) return;

	if(i > j) {
		id[i] = j; 
		pt[j] += pt[i];
	} else {
		id[j] = i;	
		pt[i] += pt[j];
	}
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	for ( ; cin >> N >> K && N + K != 0; ) {
		build();

		for (int i = 1; i <= N; i++) {
			cin >> pt[i];
		}
		int ans = 0;
		for (int i = 0; i < K; i++) {
			cin >> Q >> X >> Y;

			if (Q == 1) {
				unite(X, Y);
			} else {
				ans += sum(X, Y);
			}
		}
		cout << ans << "\n";
	}
    return 0;
}
