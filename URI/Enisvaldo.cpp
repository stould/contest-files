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

const int MAXN = 110;

int T, N;
vector<int> cnt[MAXN];

bool in(int v) {
	return v >= 10 && v <= 100;
}

int main(void) {
	cin >> T;

	while (T--) {
		cin >> N;

		for (int i = 0; i < MAXN; i++) {
			cnt[i].clear();
		}

		int type, val;
		int ans = 0;
		
		for (int i = 0; i < N; i++) {
			cin >> type >> val;
			
			cnt[type].push_back(val);
		}

		for (int i = 1; i < MAXN; i++) {
			sort(cnt[i].begin(), cnt[i].end());

			int best = 0;
			int M = (int) cnt[i].size();

			if (M != 0) best = cnt[i][M - 1];
									 
			
			for (int j = M - 1; j >= 0; j--) {
				if (in(cnt[i][j])) {
					best = cnt[i][j];
					break;
				}
			}

			ans += best;
		}

		cout << ans << endl;
	}
	return 0;
}
