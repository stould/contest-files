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

const int MAXN = 210;

int N, M;
string sign, base;
string dp[MAXN][5];
vector<pair<char, pair<int, char> > > graph[MAXN];

string func(int pos, int pref, string curr_build) {
	if (pos == N) {
		//cout << curr_build << "\n";
		return curr_build;
	} else {
		string& ans = dp[pos][pref];

		if (ans == "") {
			ans = "zzzzzzzzzzzzzzzzzz";

			for (int i = 0; i < (int) sign.size(); i++) {
				char curr = 'a' + i;
				char curr_sign = sign[i];
				
				if (pref && curr < base[pos]) continue;

				bool valid = true;
				
				for (int j = 0; j < (int) graph[i].size(); j++) {
					int prev_pos = graph[i][j].second.first;
					char kind = graph[i][j].second;

					if (prev_pos < pos) {
						char prev_kind = sign[curr_build[prev_pos] - 'a'];
						
						if (prev_kind != kind) {
							valid = false;
						}
					}
				}				
			}
		}
		
		return ans;
	}
}

int main(void) {
	cin >> sign >> N >> M;

	for (int i = 0; i < M; i++) {
		int P0, P1;
		char V0, V1;
		
		cin >> P0 >> V0 >> P1 >> V1;

		P0 -= 1;
		P1 -= 1;

		graph[P0].push_back(make_pair(V0, make_pair(P1, V1)));
		graph[P1].push_back(make_pair(V1, make_pair(P0, V0)));
	}

	cin >> base;

	string ans = func(0, 1, "");

	cout << ans << "\n";
	
	return 0;
}
