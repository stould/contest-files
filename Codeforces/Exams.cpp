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

const int MAXN = 5050;
const int INF = INT_MAX / 3;

int N;
pair<int, int> P[MAXN];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i].first >> P[i].second;
	}

	sort(P, P + N);
	
	int last = 0;
	
	for (int i = 0; i < N; i++) {
		int best = last;
		if (P[i].first >= best) {
			best = P[i].first;
		}
		if (P[i].second >= last) {
			best = min(best, P[i].second);
		}
		last = best;
	}

	cout << last << "\n";
	
    return 0;
}
