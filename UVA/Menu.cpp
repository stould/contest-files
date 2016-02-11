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

const int MAXN = 120;
const int INF = INT_MAX / 4;
const double EPS = 1e-8;

int K, N, M;
int C[MAXN], V[MAXN];
//benefit/cost
pair<double, int> dp[25][110][60][60];
vector<int> path;

bool eq(double a, double b) {
	return fabs(a - b) < EPS;
}

pair<double, int> func(int day, int budget, int last, int seen) {
	if (budget < 0) {
		return make_pair(-INF, INF);
	} else if (day == K) {
		return make_pair(0, 0);
	} else {
		pair<double, int>& ans = dp[day][budget][last][seen];
		
		if (ans.first == -1.0) {
			ans = make_pair(-INF, INF);
			
			for (int i = 0; i < N; i++) {
				double out = V[i];
				int cost = C[i];
				
				if (i == last) {					
					out /= 2;

					if (seen >= 2) {
						out = 0.0;
					}
				}

				pair<double, int> now = func(day + 1, budget - cost, i, (i == last ? seen + 1 : 1));
				
				now.first += out;
				now.second += cost;

				if (now.first - EPS > ans.first) {
					ans = now;
				} else if (eq(now.first, ans.first)) {
					if (now.second < ans.second) {
						ans = now;
					}
				}
			}
		}
		
		return ans;
	}
}
void print_path(int day, int budget, int last, int seen) {
	if (budget < 0) {
		return;
	} else if (day == K) {
		return;
	} else {
		pair<double, int> ans = make_pair(-INF, INF);
		
		int id = -1;
		int curr_budget = 0;
		int curr_seen;
		double c_out = 0;
		
		for (int i = 0; i < N; i++) {
			double out = V[i];
			int cost = C[i];
			
			if (i == last) {					
				out /= 2;
				
				if (seen >= 2) {
					out = 0.0;
				}
			}
			
			pair<double, int> now = func(day + 1, budget - cost, i, (i == last ? seen + 1 : 1));
			
			now.first += out;
			now.second += cost;

			 if (now.first - EPS > ans.first) {
				 ans = now;
				 id = i;
				 c_out = out;
				 curr_budget= budget - cost;
				 curr_seen = (i == last ? seen + 1 : 1);
			 } else if (eq(now.first, ans.first)) {
				 if (now.second < ans.second) {
					 ans = now;
					 id = i;
					 c_out = out;
					 curr_budget= budget - cost;
					 curr_seen = (i == last ? seen + 1 : 1);
				 }
			 }
		}
		path.push_back(id);		
		print_path(day + 1, curr_budget, id, curr_seen);
	}
}

int main(void) {
	while (cin >> K >> N >> M) {
		if (K == 0 && N == 0 && M == 0) {
			break;
		}
		for (int i = 0; i < N; i++) {
			cin >> C[i] >> V[i];
		}

		path.clear();
		
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 110; j++) {
				for (int k = 0; k < 60; k++) {
					for (int l = 0; l < 60; l++) {
						dp[i][j][k][l] = make_pair(-1.0, 0.0);
					}
				}
			}
		}
		
		pair<double, int> ans = func(0, M, N, 0);

		print_path(0, M, N, 0);
		
		if (ans.first < 0.0) {
			ans.first = 0.0;
		}
		
		cout << fixed << setprecision(1) << ans.first << "\n";
		
		if (!eq(ans.first, 0.0)) {
			for (int i = 0; i < (int) path.size(); i++) {
				if (i) {
					cout << " ";
				}
				cout << path[i] + 1;			
			}
		}
		cout << "\n";
	}
	return 0;
}
