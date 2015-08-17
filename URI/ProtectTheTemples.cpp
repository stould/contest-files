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

const int MAXN = 1005;

int T, N, M;
vector<int> graph[MAXN];
int deg[MAXN], on[MAXN];

bool cmp(int a, int b) {
	return deg[a] < deg[b];
}

int main(void) {
	cin >> T;

	while (T--) {
		cin >> N >> M;

		vector<int> id(N);

		for (int i = 0; i < N; i++) {
			id[i] = i;
			deg[i] = on[i] = 0;
			graph[i].clear();
		}

		for (int i = 0; i < M; i++) {
			int A, B;
			cin >> A >> B;

			A -= 1;
			B -= 1;

			graph[A].push_back(B);
			graph[B].push_back(A);
			//debug("err %d %d\n", A, B);
			
			deg[A] += 1;
			deg[B] += 1;
		}
		
		sort(id.begin(), id.end(), cmp);

		int ans = 0;

		for (int i = 0; i < N; i++) {
			if (on[id[i]]) continue;
			
			//debug("now %d\n", id[i]);
			vector<int> g, b;
			
			for (int j = 0; j < (int) graph[id[i]].size(); j++) {
				int u = graph[id[i]][j];

				if (on[u]) {
					b.push_back(u);
				} else {
					g.push_back(u);
				}
				//cout << id[i] << " " << u << " " << on[u] << "\n";
			}

			if (!g.empty()) {
				for (int j = 0; j < (int) g.size(); j++) {
					ans += 1;
					on[g[j]] = on[id[i]] = 1;
				}
			} 
		}
		cout << ans <<"\n";
	}
	return 0;
}
