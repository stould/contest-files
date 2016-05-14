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
const Int INF = 100100101001010000LL;
int N;
Int X[MAXN], Y[MAXN];
Int dp[MAXN][3];
set<int> sx, sy;

struct pol {
	Int xl, xr, yu, yl;
	bool h_xl, h_xr, h_yu, h_yl;
	
	pol() {
		xl = xr = yu = yl = 0;
		h_xl = false;
		h_xr = false;
		h_yu = false;
		h_yl = false;
	}

	Int perimeter() {
		Int ans = 0;

		vector<pair<Int, Int> > polygon;

		if (h_xl) {
			polygon.push_back(make_pair(xl, 0));
		}
		if (h_yu) {
			polygon.push_back(make_pair(0, yu));
		}
		if (h_xr) {
			polygon.push_back(make_pair(xr, 0));
		}
		if (h_yl) {
			polygon.push_back(make_pair(0, yl));
		}

		int len = polygon.size() == 2 ? 1 : polygon.size();
		
		for (int i = 0; i < len; i++) {
			int next = (i + 1) % (int) polygon.size();
			Int curr = 0.0;
			
			curr += abs(polygon[i].first - polygon[next].first) * abs(polygon[i].first - polygon[next].first);
			curr += abs(polygon[i].second - polygon[next].second) * abs(polygon[i].second - polygon[next].second);

			ans += curr;
		}
		
		if (polygon.empty()) {
			ans = INF;
		} else if (polygon.size() == 1) {
			if (!(sx.size() == 1 || sy.size() == 1)) {
				ans = INF;
			}
		}

		return ans;
	}
};

pol adapt(pol curr, Int x, Int y, int kind) {
	if (kind == 0) {
		if (curr.xl >= x) {
			curr.xl = x;
			curr.h_xl = true;
		}
		if (curr.xr <= x) {
			curr.xr = x;
			curr.h_xr = true;
		}
	} else {
		if (curr.yu <= y) {
			curr.yu = y;
			curr.h_yu = true;
		}
		if (curr.yl >= y) {
			curr.yl = y;
			curr.h_yl = true;
		}
	}
	return curr;
}

Int func(int pos, int d, pol curr) {
	if (pos == N) {
		return curr.perimeter();
	} else {
		Int& ans = dp[pos][d];

		if (ans == -1) {
			ans = INF;
			
			chmin(ans, func(pos + 1, 0, adapt(curr, X[pos], 0, 0)));
			chmin(ans, func(pos + 1, 1, adapt(curr, 0, Y[pos], 1)));
		}

		return ans;
	}
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];

		sx.insert(X[i]);
		sy.insert(Y[i]);
	}

	memset(dp, -1, sizeof(dp));

	cout << func(0, 0, pol()) << "\n";;
	
	return 0;
}
