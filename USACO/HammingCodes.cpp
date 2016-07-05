/*
  ID: jeferso1
  LANG: C++
  TASK: hamming
*/

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

int N, B, D;

vector<int> toBase(int x, int base) {
	vector<int> ans;

	if (x == 0) {
		ans.push_back(0);
	} else {
		while (x > 0) {
			ans.push_back(x % base);
			x /= base;
		}
	}
	
	return ans;
}

bool cmp(int a, int b) {
	vector<int> ba = toBase(a, 1 << B);
	vector<int> bb = toBase(b, 1 << B);

	if (ba.size() != bb.size()) {
		return ba.size() < bb.size();
	} else {
		for (int i = 0; i < (int) ba.size(); i++) {
			if (ba[i] != bb[i]) {
				return ba[i] < bb[i];
			}
		}
		return ba[0] < bb[0];
	}
}

int main(void) {
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);
	
	cin >> N >> B >> D;

	vector<int> ans;
	ans.push_back(0);
	
	for (int i = 1; i < (1 << B); i++) {
		bool ok = true;
		for (int j = 0; j < (int) ans.size(); j++) {
			int df = __builtin_popcount(i ^ ans[j]);
			
			if (df < D) {
				ok = false;
			}
		}
		if (ok) {
			ans.push_back(i);
		}
	}

	for (int i = 0; i < N; i++) {
		if (i % 10 != 0) {
			cout << " ";
		}
		cout << ans[i];
		if ((i + 1) % 10 == 0) {
			cout << endl;
		}		
	}
	if (N % 10 != 0) {
		cout << endl;
	}		
	return 0;
}
