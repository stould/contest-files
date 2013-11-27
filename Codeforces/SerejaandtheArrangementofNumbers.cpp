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

const int MAXN = 2000006;

int N, M;

pair<int, int> p[MAXN];

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second > b.second;
}

int main(void) {
	N = in();
	M = in();

	int i;

	for (i = 0; i < M; i++) {
		p[i].first = in();
		p[i].second = in();
	}

	sort(p, p + M, cmp);

	Int sum = (Int) p[0].second;
	Int ans = sum;
	int us = 1;

	for (i = 2; i <= M; i++) {
		sum += p[i - 1].second;
		if (i % 2 == 0) {
			Int cnt = (Int) i * (i - 1) / 2 + i / 2;
			if (cnt > N) break;
		} else {
			Int cnt = (Int) i * (i - 1) / 2 + 1;			
			if (cnt > N) break;
		}
		chmax(ans, sum);
	}

	cout << ans << "\n";

    return 0;
}