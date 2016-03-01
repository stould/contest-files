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

const int MAXN = 40005;
const int INF = INT_MAX / 3;

int N, Q;
vector<int> treeA[MAXN], treeB[MAXN];
vector<int> ds1, ds2;
double len;

vector<int> diameter(vector<int> tree[MAXN], int L) {
	vector<int> ans(L + 1), dst(L + 1);
	
	queue<int> q;
	q.push(1);
	fill(dst.begin(), dst.end(), INF);

	dst[1] = 0;

	int last_len = 0, last = 1;

	for ( ; !q.empty(); ) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < (int) tree[now].size(); i++) {
			int next = tree[now][i];

			if (dst[now] + 1 < dst[next]) {
				dst[next] = dst[now] + 1;
				q.push(next);
				if (dst[next] > last_len) {
					last_len = dst[next];
					last = next;
				}
			}
		}
	}

	last_len = 0;

	q.push(last);
	fill(dst.begin(), dst.end(), INF);

	dst[last] = ans[last] = 0;

	for ( ; !q.empty(); ) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < (int) tree[now].size(); i++) {
			int next = tree[now][i];

			if (dst[now] + 1 < dst[next]) {
				dst[next] = ans[next] = dst[now] + 1;
				q.push(next);
				if (dst[next] > last_len) {
					last_len = dst[next];
					last = next;
				}
			}
		}
	}

	q.push(last);
	fill(dst.begin(), dst.end(), INF);

	dst[last] = 0;

	for ( ; !q.empty(); ) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < (int) tree[now].size(); i++) {
			int next = tree[now][i];

			if (dst[now] + 1 < dst[next]) {
				dst[next] = dst[now] + 1;
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= L; i++) {
		chmax(ans[i], dst[i]);
	}

	ans[0] = last_len;
	
	return ans;
}

int main(void) {
	for ( ; scanf("%d%d", &N, &Q) == 2; ) {
		int A, B;

		for (int i = 0; i <= max(N, Q); i++) {
			treeA[i].clear();
			treeB[i].clear();
		}

		for (int i = 0; i < N - 1; i++) {
			scanf("%d%d", &A, &B);
			treeA[A].push_back(B);
			treeA[B].push_back(A);
		}
		for (int i = 0; i < Q - 1; i++) {
			scanf("%d%d", &A, &B);
			treeB[A].push_back(B);
			treeB[B].push_back(A);
		}

		len = 0.0;
		
		ds1 = diameter(treeA, N);
		ds2 = diameter(treeB, Q);

		sort(ds2.begin() + 1, ds2.end());

		vector<Int> acc(Q + 1);

		for (int i = 1; i <= Q; i++) {
			acc[i] = acc[i - 1] + ds2[i];
		}
		vector<int> vs(N + 1);
		
		for (int i = 1; i <= N; i++) {
			int l = 1, h = Q, m;
			int best = Q;
			
			while (l <= h) {
				m = (l + h) / 2;
				
				//cout << m << " " << ds1[i] + 1 + ds2[m] << " " << max(ds1[0], ds2[0]) << "\n";
				
				if (ds1[i] + 1 + ds2[m] > max(ds1[0], ds2[0])) {
					best = m;
					h = m - 1;
				} else {
					l = m + 1;
				}
			}
			
			double curr = 0.0;

			if (best == 1) {
				curr += Q * ds1[i] + (acc[Q] - acc[best - 1]) + Q;
			} else if (best == Q) {
				curr += Q * max(ds1[0], ds2[0]);
			} else {			
				curr += (best - 1) * max(ds1[0], ds2[0]);
				curr += (Q - best + 1) * ds1[i] + (acc[Q] - acc[best - 1]) + (Q - best + 1);
			}

			vs[i] = curr;
			len += curr;
		}
		
		printf("%.3lf\n", len / (double) (N * Q));
	}
    return 0;
}
