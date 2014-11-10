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

int N, M, K;
string S;
vector<string> kinds[35];

vector<string> split(string s) {
	istringstream ss(s);
	string tmp;

	vector<string> ans;

	while (ss >> tmp) {
		ans.push_back(tmp);
	}

	return ans;
}

int main(void) {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		getline(cin, S);
		
		vector<string> vs = split(S);

		for (int j = 4; j < (int) vs.size() - 1; j++) {
			kinds[j - 4].push_back(vs[j]);
		}
		M = vs.size() - 5;
	}
    return 0;
}
