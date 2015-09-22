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

const int MAXN = 100005;

int N, M;
int C[MAXN];
vector<int> tree[MAXN];
bool vis[MAXN];

int main(void) {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> C[i];
	}

	int A, B;
	for (int i = 0; i < N - 1; i++) {
		cin >> A >> B;
		tree[A].push_back(B);
		tree[B].push_back(A);
	}

	queue<pair<int, int> > q;
	q.push(make_pair(1, C[1]));
	vis[1] = true;

	int ans = 0;
	
	while (!q.empty()) {
		int node = q.front().first;
		int acc = q.front().second;
		q.pop();
		
		if (acc > M) {
			continue;
		}

		bool seen = false;
		
		for (int i = 0; i < (int) tree[node].size(); i++) {
			int u = tree[node][i];
			
			if (!vis[u]) {
				int ac = acc;
				
				if (C[u] == 0) {
					ac = 0;
				} else {
					ac += 1;
				}
				seen = true;
				vis[u] = true;
				q.push(make_pair(u, ac));
			}				
		}
		if (!seen) {
			ans += 1;
		}
	}

	cout << ans << "\n";
	
	return 0;
}
