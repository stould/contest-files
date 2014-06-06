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

char c;
string S;

vector<string> split(string s) {
	vector<string> ans;
	istringstream ss(s);
	string tmp;

	for ( ; ss >> tmp; ) {
		ans.push_back(tmp);
	}
	return ans;
}

int main(void) {
	cin >> c;
	getline(cin, S);
	getline(cin, S);
	vector<string> vs = split(S);
	int por = 0;

	for (int i = 0; i < (int) vs.size(); i++) {
		for (int j = 0; j < (int) vs[i].size(); j++) {
			if (vs[i][j] == c) {
				por += 1;
				break;
			}
		}							 
	}

	cout << fixed << setprecision(1) << (por / (double) vs.size()) * 100.0 << "\n";
    return 0;
}
