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

int A, B, C, D;
set<pair<int, int> > ans;

void dfs(int x, int y) {
	if ((Int) x * y == (Int) C * D) {
		ans.insert(make_pair(x, y));
	} else {
		if (x % 2 == 0) {
			dfs(x / 2, y);
		}
		if (x % 3 == 0) {
			dfs(x / 3, y);
		}
		if (y % 2 == 0) {
			dfs(x, y / 2);
		}
		if (y % 3 == 0) {
			dfs(x, y / 3);
		}
	}
}

int main(void) {
	cin >> A >> B >> C >> D;

	dfs(A, B);

	if (ans.empty()) {
		cout << "-1\n";
	} else {
		set<pair<int, int> >::iterator it;

		for (it = ans.begin(); it != ans.end(); it++) {
			cout << it->first << " " << it->second << "\n";
		}
	}

    return 0;
}
