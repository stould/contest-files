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

const int MAXN = 60;

int T, N, S;
string NM[MAXN];
bool vis[MAXN], fromRoot[MAXN];
vector<int> graph[MAXN];

set<int> ans;

bool dfs(int p, int goal) {
	vis[p] = true;
	
	if (p == goal) {
		return true;
	}	
	
	for (int i = 0; i < (int) graph[p].size(); i++) {
		if (!vis[graph[p][i]] && dfs(graph[p][i], goal)) {
			return true;
		}
	}
	
	return false;
}

bool find(int f,  int t) {
	memset(vis, false, sizeof(vis));
	return dfs(f, t);
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> S;

		for (int i = 0; i < MAXN; i++) {
			graph[i].clear();
			vis[i] = 0;
		}

		ans.clear();		
		map<int, string> mp;

		for (int i = 1; i <= N; i++) {
			cin >> NM[i];
			mp[i] = NM[i];
		}

		for (int i = 1; i <= N; i++) {
			int C, U;
			cin >> C;

			for (int j = 0; j < C; j++) {
				cin >> U;
				graph[i].push_back(U);
			}
		}
		
		cout << "E-Mail #" << t << ":" << endl;

		for (int i = 1; i <= N; i++) {
			if (i != S) {
				fromRoot[i] = find(S, i);
				
				if (fromRoot[i]) {
					for (int j = 1; j <= N; j++) {
						if (j != S && i != j && find(i, j) && find(j, i)) {
							ans.insert(j);
						}
					}
				}
			}
		}
		
		if (ans.empty()) {
			cout << "E-Mail seguro!" << endl;
		} else {
			for (set<int>::iterator it = ans.begin(); it != ans.end(); it++) {
				for (int i = 0; i < (int) graph[*it].size(); i++) {
					ans.insert(graph[*it][i]);
				}
			}
					
			for (set<int>::iterator it = ans.begin(); it != ans.end(); it++) {
				cout << mp[*it] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
