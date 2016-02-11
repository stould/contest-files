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

const int MAXN = 100005;
const Int INF = 100100101001010010LL;

int N, M;
Int P[MAXN];
Int cst[MAXN];
Int pos[MAXN][2];
Int dp[MAXN][2];

map<Int, vector<int> > L;

Int func(int id, int side) {
	if (id == M - 1) {
		return 0;
	} else {
		Int& ans = dp[id][side];

		if (ans == -1LL) {
			ans = INF;
			
			Int l = abs(pos[id][side] - pos[id + 1][0]) + cst[id + 1] + func(id + 1, 1);
			Int r = abs(pos[id][side] - pos[id + 1][1]) + cst[id + 1] + func(id + 1, 0);
			
			//cout << id << " " << abs(pos[id][side] - pos[id + 1][0]) + cst[id + 1] << endl;
			//cout << id << " " << abs(pos[id][side] - pos[id + 1][1]) + cst[id + 1] << endl;

			chmin(ans, min(l, r));
		}

		return ans;
	}
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
		
		L[P[i]].push_back(i);		
	}
	
	int id = 1;

	for (auto i : L) {
		sort(L[i.first].begin(), L[i.first].end());
		
		pos[id][0] = L[i.first][0];
		pos[id][1] = L[i.first][L[i.first].size() - 1];
		
		int curr = 0;

		for (int j = 1; j < (int) L[i.first].size(); j++) {
			curr += L[i.first][j] - L[i.first][j - 1];
		}

		cst[id] = curr;

		id += 1;
	}

	M = id;

	memset(dp, -1LL, sizeof(dp));
	
	cout << N + func(0, 0) << endl;

	return 0;
}
