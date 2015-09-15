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

const int MAXN = 100005;

int N, M;
int P[MAXN], cnt[MAXN];
int L[MAXN], R[MAXN];
int ans[MAXN];

int main(void) {
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;

	set<int> ps;
	
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		if (P[i] > 0 && P[i] <= 100000) {
			cnt[P[i]] += 1;

			if (cnt[P[i]] >= P[i]) {
				ps.insert(P[i]);
			}
		}
	}

	vector<int> poss(ps.begin(), ps.end());
	
	for (int i = 0; i < M; i++) {
		cin >> L[i] >> R[i];
		L[i] -= 1;
		R[i] -= 1;
	}

	for (int i = 0; i < (int) poss.size(); i++) {
		for (int j = 0; j < N; j++) {
			cnt[j] = 0;

			if (P[j] == poss[i]) {
				cnt[j] = 1;
			}
			if (j > 0) {
				cnt[j] += cnt[j - 1];
			}
		}
		for (int j = 0; j < M; j++) {
			int seen = cnt[R[j]];

			if (L[j] != 0) {
				seen -= cnt[L[j] - 1];
			}

			ans[j] += seen == poss[i];
		}
	}

	for (int i = 0; i < M; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
