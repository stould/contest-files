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

const int MAXN = 1010;

int N;

pair<int, int> p[MAXN];

bool cmp(const pair<int, int> a, const pair<int, int> b) {
	if (a.second != b.second) {
		return a.second > b.second;
	} else {
		return a.first < b.first;
	}
}

int main(void) {
	int test = 1;
	int i;

	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		for (i = 0; i < N; i++) {
			scanf("%d%d", &p[i].first, &p[i].second);
		}
		sort(p, p + N, cmp);

		int ans = 0;
		int l = 0;

		for (i = 0; i < N; i++) {
			l += p[i].first;		

			ans = max(ans, l + p[i].second);
		}

		printf("Case %d: %d\n", test++, ans);
	}

    return 0;
}
