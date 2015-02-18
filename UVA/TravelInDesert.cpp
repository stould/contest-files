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

const int MAXN = 110;
const double INF = 10101010101010.0;
const double EPS = 1e-7;
int N, E, S, T;
int path[MAXN];
vector<pair<int, pair<double, double> > > graph[MAXN];
double cp_len[MAXN], cp_tp[MAXN];

struct MyCmp {
	bool operator()(int a, int b) {
		return cp_len[a] > cp_len[b];	   
	}
};

pair<double, double> func(double min_tp) {
	fill(path, path + N + 1, -1);
	fill(cp_len, cp_len + N + 1, INF);
	fill(cp_tp, cp_tp + N + 1, INF);

	cp_len[S] = cp_tp[S] = 0;
	priority_queue<int, vector<int>, MyCmp> q;
	q.push(S);
	
	for ( ; !q.empty(); ) {
		int now = q.top();
		q.pop();

		
		//		printf("%d %.2lf %.2lf -----\n", now, cp_len[now], cp_tp[now]);

		for (int i = 0; i < (int) graph[now].size(); i++) {
			int u = graph[now][i].first;
			double u_len = graph[now][i].second.first;
			double u_tp = graph[now][i].second.second;
			


			if (u_tp > min_tp) continue;

			if (cp_len[now] + u_len < cp_len[u]) {

				q.push(u);
				cp_len[u] = cp_len[now] + u_len;
				cp_tp[u] = max(cp_tp[now], u_tp);
				//	printf("%d %.2lf %.2lf\n", u, u_len, u_tp);
				path[u] = now;				
			}
		}
		//		printf("\n");
	}

	return make_pair(cp_len[T], cp_tp[T]);
}

int main(void) {
	for ( ; scanf("%d%d", &N, &E) == 2; ) {
		scanf("%d%d", &S, &T);
		int f, t;
		double x, y;

		for (int i = 1; i < MAXN; i++) {
			graph[i].clear();
		}

		for (int i = 0; i < E; i++) {			
			scanf("%d%d%lf%lf", &f, &t, &x, &y);
			graph[f].push_back(make_pair(t, make_pair(y, x)));
			graph[t].push_back(make_pair(f, make_pair(y, x)));
        } 

		double l = 0.0, h = 100.0, m;
		pair<double, double> tmp, f_ans;
		double best = INF;
		for (int x = 0; x < 70; x++) {
			m = (l + h) / 2.0;
			f_ans = func(m);

			//			printf("%.2lf %.2lf %.18lf\n", f_ans.first, f_ans.second, m);

			if (f_ans.first < INF) {
				best = min(best, m);
				h = m;
			} else {
				l = m;
			}
		}
		f_ans = func(best);
		vector<int> rev;
		int p = T;

		for ( ; p != -1; ) {
			rev.push_back(p);
			p = path[p];
		}
		reverse(rev.begin(), rev.end());
		for (int i = 0; i < (int) rev.size(); i++) {
			printf("%d", rev[i]);
			if (i != rev.size() - 1) printf(" ");
		}
		printf("\n%.1lf %.1lf\n", f_ans.first, f_ans.second);
	}
    return 0;
}
