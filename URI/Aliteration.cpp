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

vector<string> split(string p) {
	vector<string> ans;
	istringstream ss(p);
	string tmp;

	for ( ; ss >> tmp; ) {
		ans.push_back(tmp);
	}
	return ans;
}

int main(void) {
	for ( ; getline(cin, S); ) {
		vector<string> vs = split(S);
		int N = vs.size();
		int ans = 0;
		
		for (int i = 0; i < N; i++) {
			int j = i + 1;

			for ( ; j < N && tolower(vs[j][0]) == tolower(vs[j - 1][0]); j++) {
				
			}
			if (i + 1 != j) ans += 1;
			i = j - 1;
		}
		
		cout << ans << "\n";
	}
    return 0;
}
