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

string S;

vector<int> split(string s) {
	vector<int> ans;
	istringstream ss(s);
	int t;

	while (ss >> t) {
		ans.push_back(t);
	}
	return ans;
}

int main(void) {
	for ( ; getline(cin, S); ) {
		vector<int> vs = split(S);
		int N = (int) vs.size();

		int sum = 0, ans = 0;
		for (int i = 0; i < N; i++) {
			chmax(ans, sum);
			sum += vs[i];
			if (sum < 0) sum = 0;
		}
		chmax(ans, sum);
		printf("%d\n", ans);
	}
    return 0;
}
