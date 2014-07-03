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

vector<string> split(string s) {
	vector<string> ans;
	string tmp;
	istringstream ss(s);

	for ( ; ss >> tmp; ) {
		ans.push_back(tmp);
	}
	return ans;
}
int main(void) {
	getline(cin, S);
	vector<string> vs = split(S);
	for (int x = 0; x < (int) vs.size(); x++) {
		for (int i = 0; i < (int) vs[x].size(); i++) {
			if (i % 2 == 1) {
				putchar(vs[x][i]);
			}
		}
		printf(" ");
	}
	puts("");
    return 0;
}
