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
const Int INF = 10101010101000LL;
int N, M, K, P;
Int Q;
vector<pair<int, Int> > graph[MAXN];
Int dist[MAXN], T[MAXN];
int used[MAXN];

struct MyLess {
    bool operator()(int x, int y) {
        return dist[x] > dist[y];
    }
};

int main(void) {
	scanf("%d%d%d", &N, &M, &K);
	int A, B;
	Int C;

	for (int i = 0; i < M; i++) {
		scanf("%d%d%I64d", &A, &B, &C);
		A -= 1;
		B -= 1;
		graph[A].push_back(make_pair(B, C));
		graph[B].push_back(make_pair(A, C));
	}

	int ans = 0;
	
	for(int i = 0; i < N; i++) {
		dist[i] = T[i] = INF;
		used[i] = false;
	}

	for (int i = 0; i < K; i++) {
		scanf("%d%I64d", &P, &Q);
		P -= 1;

		if (T[P] != INF) {
			ans += 1;
		}
		chmin(T[P], Q);
	}


	priority_queue<pair<Int, int>, vector<pair<Int, int> >, greater<pair<Int, int> > > q;
	dist[0] = 0LL;
 	q.push(make_pair(0LL, 0));

	for (int i = 1; i < N; i++) {
		if (T[i] != INF) {
			q.push(make_pair(T[i], i));
			dist[i] = T[i];
		}
	}


	while(!q.empty()) {
		int cost = q.top().first;
		int now = q.top().second;

		q.pop();
		if (cost > dist[now]) continue;
		
		for(int i = 0; i < (int) graph[now].size(); i++) {
			int next = graph[now][i].first;
            Int aux_dist = dist[now] + graph[now][i].second;
            Int actual_dist = dist[next];

			if (aux_dist <= T[next]) {
				if (!used[next] && T[next] != INF) {
					used[next] = true; 
					ans += 1;
				}
			}
            if(aux_dist < actual_dist) {
                dist[next] = aux_dist;
                q.push(make_pair(aux_dist, next));
            }
        }
    }	

	printf("%d\n", ans);

    return 0;
}
