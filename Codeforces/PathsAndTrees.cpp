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

const int MAXN = 300005;

int N, M, U;
vector<pair<int, pair<int, int> > > graph[MAXN];
Int dist[MAXN];
Int W[MAXN];
pair<int, int> prv[MAXN];

struct MyLess {
    bool operator()(int x, int y) {
        return dist[x] > dist[y];
    }
};

void dijsktra(int source) {
	for(int i = 0; i < MAXN; i++) {
		dist[i] = INT_MAX;
	}
	priority_queue<pair<int, int> > q;
	dist[source] = 0;
 	q.push(make_pair(0, source));
	prv[source] = make_pair(-1, -1);

	while(!q.empty()) {
		int tmp = q.top().second;
		int val= q.top().first;
		q.pop();

		if (dist[tmp] > val) continue;

		for(int i = 0; i < (int) graph[tmp].size(); i++) {
            int aux_dist = dist[tmp] + graph[tmp][i].second.first;
            int actual_dist = dist[graph[tmp][i].first];
            if(aux_dist < actual_dist) {
                dist[graph[tmp][i].first] = aux_dist;
                q.push(make_pair(-aux_dist, graph[tmp][i].first));
				//				cout << "pr " << graph[tmp][i].first << " " << tmp << " " << graph[tmp][i].second.second << " done\n";
				prv[graph[tmp][i].first] = make_pair(tmp, graph[tmp][i].second.second);
            }
        }
    }
}


int main(void) {
	cin >> N >> M;

	int A, B, C;
	
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		
		graph[A].push_back(make_pair(B, make_pair(C, i + 1)));
		graph[B].push_back(make_pair(A, make_pair(C, i + 1)));

		W[i + 1] = C;
	}

	cin >> U;
	
	dijsktra(U);

	set<int> vs;

	for (int i = 1; i <= N; i++) {
		if (i != U) {
			int curr = i;

			while (curr != -1) {
				vs.insert(prv[curr].second);
				curr = prv[curr].first;
			}
		}
	}

	Int ans = 0;

	for (set<int>::iterator it = vs.begin(); it != vs.end(); it++) {		
		ans += W[*it];
	}

	cout << ans << "\n";
	
	for (set<int>::iterator it = vs.begin(); it != vs.end(); it++) {
		if (*it != -1) {
			cout << *it << " ";
		}
	}
	cout << "\n";
	return 0;
}
