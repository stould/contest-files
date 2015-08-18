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

const int MAXN = 1000005;

int T, N;
int P[MAXN], tree[MAXN];

void add(int pos, int val) {
	for (int i = pos; i <= N; i += (i & (-i))) {
		tree[i] += val;
	}
}

int sum(int pos) {
	int ans = 0;
	for (int i = pos; i > 0; i -= (i & (-i))) {
		ans += tree[i];
	}
	return ans;
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> P[i];
			tree[i] = 0;
		}

		int ans = 0;

		for (int i = N - 1; i >= 0; i--) {
			if (sum(P[i] - 1)) {
				ans += 1;
			}
			add(P[i], i);
		}

		cout << "Case #" << t << ": " << ans << "\n";
	}
	return 0;
}
