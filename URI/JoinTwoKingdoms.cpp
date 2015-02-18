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

		vector<int> ds1 = diameter(treeA, N);
		vector<int> ds2 = diameter(treeB, Q);

		double len = 0.0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= Q; j++) {
				len += (double) max(ds1[0], max(ds2[0], ds1[i] + 1 + ds2[j]));
			}
		}
		
		printf("%.3lf\n", len / (double) (N * Q));
	}
    return 0;
}
