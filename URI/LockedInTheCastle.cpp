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

		queue<int> q;
		q.push(1);
		
		vis[1] = true;

		int v = 0;
		set<int> keyring;

		//key collect
		for ( ; !q.empty(); ) {
			int now = q.front();
			q.pop();

			for (int i = 0; i < (int) key[now].size(); i++) {
				keyring.insert(key[now][i]);
			}
			
			for (int i = 0; i < (int) graph[now].size(); i++) {
				int next = graph[now][i];

				if (!vis[next] && keyring.count(next)) {
					q.push(next);
					vis[next] = true;
				}
			}
		}

		memset(vis, false, sizeof(vis));
		q.push(1);
		
		for ( ; !q.empty(); ) {
			int now = q.front();
			q.pop();
			

			v += 1;
			
			for (int i = 0; i < (int) graph[now].size(); i++) {
				int next = graph[now][i];

				if (!vis[next] && keyring.count(next)) {
					q.push(next);
					vis[next] = true;
				}
			}
		}
				
		if (v == N) {
			cout << "sim\n";
		} else {
			cout << "nao\n";
		}

	}
	
    return 0;
}
