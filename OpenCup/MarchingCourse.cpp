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

const int MAXN = 1010;
const double INF = 10010010101001010.0;

int N, M, P;
vector<pair<int, pair<int, int> > > G[MAXN];
double dp[220][MAXN];
bool mark[220][MAXN];

double func(int id, int len, double buff) {
	if (len == 0) {
		if (id == 1) {
			return 0;
		} else {
			return -INF;
		}
	} else {
		double& ans = dp[id][len];

		if (!mark[id][len]) {
			ans = -INF;
			mark[id][len] = true;

			for (int i = 0; i < (int) G[id].size(); i++) {
				int u = G[id][i].first;
				int D = G[id][i].second.first;
				int V = G[id][i].second.second;
				
				if (len - 1 >= 0) {
					chmax(ans, V / (double) D + func(id, len - 1, buff + V / (double) D));
				}
				
				if (len - D >= 0) {
					chmax(ans, V + func(u, len - D, buff + V));
				}
			}
		}
			
		return ans;
	}
}

int main(void) {
	cin >> N >> M >> P;

	for (int i = 0; i < M; i++) {
		int A, B, D, V;

		cin >> A >> B >> D >> V;
		
		G[A].push_back(make_pair(B, make_pair(D, V)));
		G[B].push_back(make_pair(A, make_pair(D, V)));
	}

	memset(mark, false, sizeof(mark));
	
	cout << fixed << setprecision(10) << func(1, P, 0) << endl;

	return 0;
}
