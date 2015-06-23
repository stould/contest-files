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
const Int INF = 1001010100101000LL;

int N, M, U;
vector<pair<int, pair<Int, int> > > graph[MAXN];
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
		dist[i] = INF;
	}
	
	priority_queue<pair<Int, int> > q;
	dist[source] = 0;
 	q.push(make_pair(0, source));
	prv[source] = make_pair(-1, -1);

	while(!q.empty()) {
		int tmp =  q.top().second;
		Int val = -q.top().first;
		q.pop();

		if (dist[tmp] < val) continue;

		for(int i = 0; i < (int) graph[tmp].size(); i++) {
			int next_id = graph[tmp][i].first;
			int edge_id = graph[tmp][i].second.second;
			Int edge_dist = graph[tmp][i].second.first;

			//cout << edge_id << "\n";
			
            Int aux_dist = dist[tmp] + edge_dist;
            Int actual_dist = dist[next_id];			
			
            if (aux_dist < actual_dist) {
                dist[next_id] = aux_dist;
                q.push(make_pair(-aux_dist, next_id));
				//cout << "pr " << graph[tmp][i].first << " " << tmp << " " << graph[tmp][i].second.second << " done\n";
				prv[next_id] = make_pair(tmp, edge_id);
            } else if (aux_dist == actual_dist) {
				if (W[prv[next_id].second] > edge_dist) {
					prv[next_id].second = edge_id;					
				}
			}
        }
    }
}


int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;

	int A, B;
	Int C;
	
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
			vs.insert(prv[i].second);			
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
