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

const int MAXN = 1005;
const int MAX_M = 1000006;

const Int INF = 1010101010000101000LL;
int N, M, C;
Int W[MAX_M], S[MAX_M];

Int dp[MAXN][6 * MAXN];

struct data {
	int l, r;
	Int cost;

	data(){}

	data(int _l, int _r, Int _cost): l(_l), r(_r), cost(_cost){}

	bool operator<(const data& other) const {
		if (l != other.l) {
			return l < other.l;
		} else {
			return r > other.r;
		}
	}
};

vector<data> dt;

Int func(int id, int data_pos) {
	if (id > N) {
		return 0LL;
	} else if (data_pos >= C) {
		return INF;
	} else {
		Int& ans = dp[id][data_pos];

		if (ans == -1LL) {
			ans = func(id, data_pos + 1);

			if (dt[data_pos].l <= id) {
				chmin(ans, dt[data_pos].cost + func(dt[data_pos].r + 1, data_pos + 1));
			}
		}

		return ans;
	}
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> C;

	S[0] = 0LL;

	for (int i = 1; i <= M; i++) {
		cin >> W[i];
		S[i] = S[i  - 1] + W[i];
	}
	int Ai, Bi, Ci, Di;
	for (int i = 0; i < C; i++) {
		cin >> Ai >> Bi >> Ci >> Di;
		
		Int curr_cost = S[Di] - S[Ci - 1];

		dt.push_back(data(Ai, Bi, curr_cost));
	}

	sort(dt.begin(), dt.end());
	memset(dp, -1LL, sizeof(dp));

	Int ans;

	if (dt[0].l > 1) {
		ans = INF;
	} else {
		ans = func(1, 0);
	}

	if (ans >= INF) {
		cout << "impossivel\n";
	} else {
		cout << ans << "\n";
	}
    return 0;
}
