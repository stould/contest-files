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

int N, M;
vector<int> graph[MAXN];
vector<int> key[MAXN];
bool vis[MAXN];

int main(void) {
	for ( ; cin >> N >> M; ) {
		int A, B;

		for (int i = 0; i <= N; i++) {
			graph[i].clear();
			key[i].clear();
			vis[i] = false;
		}
		
		for (int i = 0; i < M; i++) {
			cin >> A >> B;
			
			graph[A].push_back(B);
			graph[B].push_back(A);
		}

		for (int i = 2; i <= N; i++) {
			cin >> A;
			key[A].push_back(i);
		}

		set<int> keyring, seen;

		for (int i = 0; i < key[1].size(); i++) {
			keyring.insert(key[1][i]);
		}
		
		for ( ; ; ) {
			queue<int> q;
			vector<int> nokey;
			q.push(1);

			memset(vis, false, sizeof(vis));			
			vis[1] = true;

			for ( ; !q.empty(); ) {
				int now = q.front();
				q.pop();
				
				seen.insert(now);
				
				for (int i = 0; i < (int) graph[now].size(); i++) {
					int next = graph[now][i];
					
					if (!vis[next]) {
						if (keyring.count(next)) {
							q.push(next);
							vis[next] = true;

							for (int j = 0; j < key[next].size(); j++) {
								keyring.insert(key[next][j]);
							}
						} else {
							nokey.push_back(next);
						}
					}
				}
			}
			bool ok = false;

			for (int i = 0; i < (int) nokey.size(); i++) {
				if (keyring.count(nokey[i])) {
					ok = true;
				}
			}

			if (!ok) break;
		}
				
		if (seen.size() == N) {
			cout << "sim\n";
		} else {
			cout << "nao\n";
		}

	}
	
    return 0;
}
