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

int N;
vector<int> Y, B;

int main(void) {
	cin >> N;

	int di, ci;
	
	for (int i = 0; i < N; i++) {
		cin >> di >> ci;
		if (di == 1) {
			B.push_back(ci);
		} else {
			Y.push_back(ci);
		}
	}

	sort(B.begin(), B.end());
	sort(Y.begin(), Y.end());
	
	Int ans = 0LL;

	for (int i = 0; i < (int) B.size(); i++) {
		int diag = (int) (B[i] * sqrt(2.0));
		vector<int>::iterator it = upper_bound(Y.begin(), Y.end(), B[i] - (diag - B[i]));

		bool found = false;
		
		if (it != Y.end()) {
			if (*it <= diag) {
				ans += 1;
				Y.erase(it);
				found = true;
			}
		}
	}

	cout << ans << "\n";
	
    return 0;
}
