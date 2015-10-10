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

const int MAXN = 150;
const int INF = INT_MAX / 5;

int T, N;
int id;
map<pair<int, pair<int, int> >, int> memo;
map<int, pair<int, pair<int, int> > > rev;

vector<pair<pair<int, int>, pair<int, int> > > G;
int dst[MAXN];

int readPoint() {
	int x, y, z;
	cin >> x >> y >> z;

	cout << x << " " << y << " " << z << " => " << id << endl;
	pair<int, pair<int, int> > buff_p = make_pair(x, make_pair(y, z));
	
	if (memo.find(buff_p) != memo.end()) {
		return memo[buff_p];
	} else {
		memo[buff_p] = id;
		rev[id] = buff_p;
		return id++;
	}
}

int dist(int a, int b) {
	int xa = rev[a].first;
	int xb = rev[b].first;
	int ya = rev[a].second.first;
	int yb = rev[b].second.first;
	int za = rev[a].second.second;
	int zb = rev[b].second.second;

	//cout << xa << " " << xb << endl;
	
	return (int) round(sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb) + (za - zb) * (za - zb)));
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		id = 0;

		rev.clear();
		memo.clear();
		G.clear();	
		
		int S = readPoint();
		int E = readPoint();

		cin >> N;
		
		for (int i = 0; i < N; i++) {
			int A = readPoint();
			int B = readPoint();

			int C, D;

			cin >> C >> D;

			G.push_back(make_pair(make_pair(A, B), make_pair(C, D)));
		}

		for (int i = 0; i < id; i++) {
			for (int j = 0; j < id; j++) {
				if (i != j) {
					G.push_back(make_pair(make_pair(i, j), make_pair(0, dist(i, j))));
				}
			}
		}
		
		fill(dst, dst + MAXN, INF);
		dst[S] = 0;

		for (int i = 0; i < id - 1; i++) {
			for (int j = 0; j < (int) G.size(); j++) {
				int s    = G[j].first.first;
				int e    = G[j].first.second;
				int open = G[j].second.first;
				int len  = G[j].second.second;

				int curr_cost = dst[e];
				int next_cost  = dst[s] + len;
				
				if (open > dst[s]) {
					next_cost += open - dst[s];
				}				
				
				if (dst[s] < INF && dst[e] > next_cost) {
					cout << s << " " << e << " = " << curr_cost << " " << next_cost << endl;
					dst[e] = next_cost;
				}
			}
			cout << endl;
		}

		cout << dst[E] << endl;
	}
	return 0;
}
