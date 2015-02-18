#include <bits/stdc++.h>

using namespace std;

typedef long long Int;

const Int MOD = 1000000007;
const int MAXN = 100005;
const Int INF = 1010010100101001010LL;

int N, M;
int A, B, C;
Int dist[MAXN];
Int cnt[MAXN];
bool enq[MAXN];
vector<pair<int, Int> > graph[MAXN];

struct MyLess {
    bool operator()(int x, int y) {
        return dist[x] > dist[y];
    }
};

Int dijsktra(int source, int destiny) {
	priority_queue<pair<Int, int> > q;
 
	cnt[source] = 1LL;
	dist[source] = 0LL;

	q.push(make_pair(0, source)); 

	while (!q.empty()) {
		int tmp = q.top().second;
		Int curr_cost = -q.top().first;
   
		q.pop();

		if (dist[tmp] < curr_cost) continue;
   
		for(int i = 0; i < (int) graph[tmp].size(); i++) {
			int next = graph[tmp][i].first;
			Int cost = graph[tmp][i].second;
     
			Int aux_dist = dist[tmp] + cost;
			Int actual_dist = dist[next];
     
			if(aux_dist < actual_dist) {
				dist[next] = aux_dist;
				cnt[next] = cnt[tmp];   
				q.push(make_pair(-aux_dist, next));     
			} else if (aux_dist == actual_dist) {
				cnt[next] += cnt[tmp];
			}     
			cnt[next] = ((cnt[next] % MOD) + MOD) % MOD;
		}
	} 
 
	return ((cnt[destiny] % MOD) + MOD) % MOD;
}


int main(void) {
	for ( ; cin >> N >> M; ) {
		if (N == 0 && M == 0) break;

		for (int i = 0; i <= N; i++) {
			graph[i].clear();
			dist[i] = INF;
			cnt[i] = 0LL;
		}   
   
		for (int i = 0; i < M; i++) {
			cin >> A >> B >> C;
			graph[A].push_back(make_pair(B, C));
		}
		cout << dijsktra(1, N) << "\n";
	}
	return 0;
}
