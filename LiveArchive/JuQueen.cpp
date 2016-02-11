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
typedef unsigned uint;

const int MAXN = 4587530;
const Int INF = LLONG_MAX / 3;

int N, Q;
Int M;
string S;
Int smal[4 * MAXN];
Int larg[4 * MAXN];
Int lazy[4 * MAXN];

void relax(int node, int a, int b) {
	if (lazy[node]) {
		smal[node] += lazy[node];
		larg[node] += lazy[node];
		
		if (a != b) {
			lazy[2 * node + 0] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
	}
	lazy[node] = 0;
}

pair<Int, Int> query(int node, int l, int r, int a, int b) {
	relax(node, l, r);
	if (l > r || l > b || r < a) {
		return make_pair(INF, 0);
	} else if (l >= a && r <= b) {
		return make_pair(smal[node], larg[node]);
	} else {
		int m = (l + r) / 2;

		pair<Int, Int> aa = query(2 * node, l, m, a, b);
		pair<Int, Int> bb = query(2 * node + 1, m + 1, r, a, b);
		
		return make_pair(min(aa.first, bb.first), max(aa.second, bb.second));
	}
}

void update(int node, int l, int r, int a, int b, int val) {
	relax(node, l, r);
	
	if (l > r || l > b || r < a) {
		return;
	} else if (l >= a && r <= b) {
		lazy[node] += val;		
		relax(node, l, r);
	}  else {
		int m = (l + r) / 2;

		update(2 * node, l, m, a, b, val);
		update(2 * node + 1, m + 1, r, a, b, val);
		
		smal[node] = min(smal[2 * node], smal[2 * node + 1]);
		larg[node] = max(larg[2 * node], larg[2 * node + 1]);
	}
}

int main(void) {
	cin >> N >> M >> Q;

	int A, B, C;

	for (int i = 0; i < Q; i++) {
		cin >> S;

		//cout << "deb " << query(1, 0, N - 1, 0, N - 1).second << "\n";
		
		if (S == "state") {
			cin >> A;
			
			pair<int, int> ans = query(1, 0, N - 1, A, A);
			
			cout << ans.second << "\n";
		} else if (S == "change") {
			cin >> A >> B;
			
		   	pair<Int, Int> ans = query(1, 0, N - 1, A, A);

			//cout << ans.first << " " << ans.second << "\n";
			
			Int df = B;

			if (B > 0) {
				if (ans.second + B <= M) {
					update(1, 0, N - 1, A, A, B);
				} else {
					update(1, 0, N - 1, A, A, M - ans.second);
					df = M - ans.second;
				}
			} else {
				if (ans.first + B >= 0) {
					update(1, 0, N - 1, A, A, B);
				} else {
					//cout << "seen " << ans.first << "\n";
					update(1, 0, N - 1, A, A, -ans.first);
					df = -ans.first;
				}
			}
			cout << df << "\n";
		} else {
			cin >> A >> B >> C;

			pair<Int, Int> ans = query(1, 0, N - 1, A, B);

			Int df = C;

			//cout << ans.first << " " << ans.second << "\n";
			
			if (C > 0) {
				if (ans.second + C <= M) {
					update(1, 0, N - 1, A, B, C);
				} else {
					//cerr << "seen " << ans.second << "\n";
					update(1, 0, N - 1, A, B, M - ans.second);
					df = M - ans.second;
				}
			} else {
				if (ans.first + C >= 0) {
					update(1, 0, N - 1, A, B, C);
				} else {
					update(1, 0, N - 1, A, B, -ans.first);
					df = -ans.first;
				}
			}
			cout << df << "\n";
		}
	}
	return 0;
}
