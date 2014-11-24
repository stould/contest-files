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

const int MAXN = 3030;
const int INF = INT_MAX / 2;

int N, P[MAXN];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	vector<pair<int, int> > ans;
	
	//O(n^2)
	for (int i = 0; i < N; i++) {
		int value = P[i];
		int pos = i;

		for (int j = i; j < N; j++) {
			if (P[j] < value) {
				value = P[j];
				pos = j;
			}
		}
		if (pos != i) {
			swap(P[i], P[pos]);
			ans.push_back(make_pair(i, pos));
		}
	}

	cout << ans.size() << "\n";

	for (int i = 0; i < (int) ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
    return 0;
}
