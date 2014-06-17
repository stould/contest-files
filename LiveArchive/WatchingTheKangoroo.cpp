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

const int MAXN = 100007;
const int INF = INT_MAX / 2;

int T, N, M;
pair<int, int> P[MAXN];
int K[MAXN];

vector<pair<int, int> > vL, vR;

bool cmp1(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}
bool cmp2(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int checkL(int pos) {
	int l = 0, h = N, m;
	int ans = 0;
			
	for ( ; l <= h; ) {
		m = (l + h) / 2;

		//		printf("L = %d %d - %d\n", vL[m].first, vL[m].second, ans);

		if (pos <= vL[m].second) {
			if (pos >= vL[m].first) {
				//				printf("L = done = %d\n", pos);
				ans = max(ans, pos - vL[m].first);
			}
			h = m - 1;			
		} else {
			l = m + 1;
		}
	}
	
	return ans;
}

int checkR(int pos) {
	int l = 0, h = N, m;
	int ans = 0;
			
	for ( ; l <= h; ) {
		m = (l + h) / 2;
		
		//		printf("R = %d %d - %d\n", vR[m].first, vR[m].second, ans);
		if (pos >= vR[m].first) {
			if (pos <= vR[m].second) {
				ans = max(ans, vR[m].second - pos);
			}
			l = m + 1;
		} else {
			h = m - 1;			
		}
	}
	
	return ans;
}

int main(void) {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d", &N, &M);
				
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &P[i].first, &P[i].second);
			int mid = (P[i].first + P[i].second) / 2;
			vL.push_back(make_pair(P[i].first, mid));
			vR.push_back(make_pair(mid, P[i].second));
		}

		sort(vL.begin(), vL.end(), cmp1);
		sort(vR.begin(), vR.end(), cmp2);

		printf("Case %d:\n", t);

		for (int i = 0; i < M; i++) {
			scanf("%d", &K[i]);
			printf("%d\n", max(checkL(K[i]), checkR(K[i])));
		}		
	}
    return 0;
}
