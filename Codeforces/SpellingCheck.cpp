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

string S, T;

int ss[300], tt[300];

int main(void) {
	cin >> S >> T;

	for (int i = 0; i < 300; i++) {
		ss[i] = tt[i] = 0;
	}

	for (int i = 0; i < S.size(); i++) {
		ss[S[i]] += 1;
		if (i < S.size() - 1) {
			tt[T[i]] += 1;
		}
	}

	int cntA = 0, cntB = 0;

	vector<int> ans;
	int id = 0;

	for (int i = 0; i < 300; i++) {
		if (ss[i] > 0) {
			cntA += 1;
		}
		if (tt[i] > 0) {
			cntB += 1;
		}
	}

	if (cntA == 0 ) {
		for (int i = 0; i < S.size(); i++) {
			ans.push_back(i + 1);
		}
	} else {	
		for (int i = 0; i < (int) S.size(); i++) {
			if (S[i] != T[id]) {
				ans.push_back(i + 1);
				i += 1;
			}
			id += 1;
		}
		if (ans.size() > 1) {
			ans.clear();
		}
	}

	printf("%d\n", (int) ans.size());

	for (int i = 0; i < (int) ans.size(); i++) {
		printf("%d ", ans[i]);
	}
    return 0;
}
