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

const int INF = INT_MAX / 3;
const int MAXN = 100002;

int T, N, M;

struct interval {
	int l, r;
	interval() {}	
	interval(int ll, int rr) {
		l = ll;
		r = rr;
	}

	int dist(int x) {
		if (x < l || x > r) {
			return -INF;
		} else {
			return min(x - l, r - x);
		}
	}
	bool operator<(const interval& it) const {
		return (l != it.l) ? (l < it.l) : (r > it.r);
	}
};

int main(void) {
	T = in();

	for (int t = 1; t <= T; t++) {
		N = in();
		M = in();

		vector<interval> data;
		vector<pair<int, int> > query;

		for (int i = 0; i < N; i++) {
			int A = in();
			int B = in();			
			data.push_back(interval(A, B));
		}

		sort(data.begin(), data.end());
		sort(query.begin(), query.end());

		for (int i = 0; i < M; i++) {
			int X = in();
			query.push_back(make_pair(X, i));
		}
		
		for (int i = 0; i < (int) data.size(); i++) {
			while (i + 1 < (int) data.size() && data[i + 1].r <= data[i].r && data[i + 1].l >= data[i].l) {
				data.erase(data.begin() + i + 1);
			}
		}

		N = (int) data.size();
		vector<int> ans(M);

		int pivot = 0;

		for (int i = 0; i < M; i++) {
			while (pivot < N && data[pivot].r < query[i].first) {
				pivot += 1;
			}
			ans[query[i].second] = 0;

			if (pivot >= N) pivot--;
			
			while (pivot < N && data[pivot].l <= query[i].first) {
				if (data[pivot].r < query[i].first) {
					pivot++;
					continue;
				}
				int curr = data[pivot].dist(query[i].first);

				if (curr >= ans[query[i].second]) {
					ans[query[i].second] = curr;
				} else {
					break;
				}
				pivot++;
			}			
			pivot--;
		}
		printf("Case %d:\n", t);
		for (int i = 0; i < M; i++) {
			printf("%d\n", ans[i]);
		}
	}
    return 0;
}
