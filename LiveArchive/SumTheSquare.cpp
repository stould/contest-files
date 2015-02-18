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

int A, B;

vector<Int> seq(int x) {
	vector<Int> ans;
	ans.push_back(x);
	set<Int> mark;
	mark.insert(x);

	for ( ; ; ) {
		Int n = 0LL;
		while (x > 0LL) {
			int d = (x % 10LL);
			x /= 10LL;
			n += d * d;
		}
		if (mark.count(n)) {
			break;
		} else {
			x = n;
			ans.push_back(n);
			mark.insert(n);
		}
	}

	return ans;
}

int main(void) {
	for ( ; scanf("%d%d", &A, &B) && A + B != 0; ) {
		vector<Int> sa = seq(A), sb = seq(B);
		int ans = 1010100;

		for (int i = 0; i < (int) sa.size(); i++) {
			for (int j = 0; j < (int) sb.size(); j++) {
				if (sa[i] == sb[j]) {
					ans = min(ans, i + j + 2);
				}
			}
		}
		if (ans == 1010100) ans = 0;
		printf("%d %d %d\n", A, B, ans);
	}
    return 0;
}
