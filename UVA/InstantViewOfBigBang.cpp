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

const int MAXN = 1010;
const int INF = INT_MAX / 4;

int T, N, M;
int dst[MAXN], prv[MAXN];
<<<<<<< HEAD
vector<int> G[MAXN];
set<int> in_cycle;
bool vis[MAXN];

void dfs(int x) {
	vis[x] = true;
	in_cycle.insert(x);

	for (int i = 0; i < (int) G[x].size(); i++) {
		if (!vis[G[x][i]]) {
			dfs(G[x][i]);
		}
	}
}
=======
>>>>>>> 5945da13dd451bae3b1df8793c9c01fbb633c76c

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M;

<<<<<<< HEAD
		in_cycle.clear();
		
=======
>>>>>>> 5945da13dd451bae3b1df8793c9c01fbb633c76c
		int A, B, C;
		vector<pair<int, pair<int, int> > > E;

		for (int i = 0; i <= N; i++) {
			dst[i] = INF;
			prv[i] = i;
<<<<<<< HEAD
			G[i].clear();
=======
>>>>>>> 5945da13dd451bae3b1df8793c9c01fbb633c76c
		}
		
		for (int i = 0; i < M; i++) {
			cin >> A >> B >> C;
<<<<<<< HEAD
			G[A].push_back(B);
=======
>>>>>>> 5945da13dd451bae3b1df8793c9c01fbb633c76c
			E.push_back(make_pair(A, make_pair(B, C)));			
		}

		dst[0] = 0;

		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < M; j++) {
				int u = E[j].first;
				int v = E[j].second.first;
				int c = E[j].second.second;

				if (dst[v] > dst[u] + c) {
					dst[v] = dst[u] + c;
					prv[v] = u;
				}
			}
		}

<<<<<<< HEAD
=======
		set<int> in_cycle;

>>>>>>> 5945da13dd451bae3b1df8793c9c01fbb633c76c
		for (int j = 0; j < M; j++) {
			int u = E[j].first;
			int v = E[j].second.first;
			int c = E[j].second.second;
			
			if (dst[v] > dst[u] + c) {
<<<<<<< HEAD
				in_cycle.insert(u);
			}
		}
		cout << "Case " << t << ":";

		for (const auto& i : in_cycle) {
			if (!vis[i]) {
				dfs(i);
			}
		}
		
		if (in_cycle.empty()) {
			cout << " impossible\n";
		} else {
			for (const auto& i : in_cycle) {
				cout << " " << i;
=======
				int curr = v;

				while (!in_cycle.count(curr)) {.
					in_cycle.insert(curr);
					curr = prv[curr];
				}
			}
		}
		cout << "Case " << t << ": ";

		for (int i = 0; i < M; i++) {
			if (in_cycle.count(E[i].second.first)) {
				in_cycle.insert(E[i].first);
			}
		}

		if (in_cycle.empty()) {
			cout << "impossible\n";
		} else {
			for (const auto& i : in_cycle) {
				cout << i << " ";
>>>>>>> 5945da13dd451bae3b1df8793c9c01fbb633c76c
			}
			cout << "\n";
		}
	}
	
	return 0;
}
