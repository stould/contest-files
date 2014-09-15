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

int M, N;

vector<string> split(string S) {
	string buff;
	vector<string> ans;
	istringstream ss(S);

	while (ss >> buff) {
		ans.push_back(buff);
	}
	return ans;
}

int main(void) {
	cin >> M >> N;
	string S;
	int V;

	map<string, int> mp;

	for (int i = 0; i < M; i++) {
		cin >> S >> V;
		mp[S] = V;
	}
	for (int i = 0; i < N; i++) {
		Int ans = 0LL;
		while (getline(cin, S) && S != ".") {
			vector<string> vs = split(S);
			
			for (int j = 0; j < (int) vs.size(); j++) {
				ans += mp[vs[j]];
			}
		}
		cout << ans << "\n";
	}
    return 0;
}
