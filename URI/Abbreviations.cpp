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

vector<string> split(string S) {
	istringstream ss(S);
	vector<string> ans;
	string buff;

	for ( ; ss >> buff; ) {
		ans.push_back(buff);
	}
	return ans;
}

map<string, int > app;
string S;

bool cmp(string a, string b) {
	return app[a] * (a.size() - 2) > app[b] * (b.size() - 2);
}

bool cmp2(pair<string, string> a, pair<string, string> b) {
	return a.first[0] < b.first[0];
}

int main(void) {
	for ( ; getline(cin, S) && S != "."; ) {
		app.clear();
		map<string, string> sub;
		vector<string> s = split(S);
		vector<string> cpy = s;

		for (int i = 0; i < (int) s.size(); i++) {
			app[s[i]] += 1;
		}
		sort(s.begin(), s.end(), cmp);


		bool vis[30];
		memset(vis, false, sizeof(vis));
		vector<pair<string, string> > ans;

		for (int i = 0; i < s.size(); i++) {
			if (!vis[s[i][0] - 'a'] && s[i].size() > 2) {
				vis[s[i][0] - 'a'] = true;
				sub[s[i]] = string(1, s[i][0]) + ".";
				ans.push_back(make_pair(sub[s[i]], s[i]));
			}
		}
		sort(ans.begin(), ans.end(), cmp2);
		for (int i = 0; i < (int) cpy.size(); i++) {
			if (sub[cpy[i]] == "") {
				cout << cpy[i];
			} else {
				cout << sub[cpy[i]];
			}
			if (i != cpy.size() - 1) {
				cout << " ";
			}
		}
		cout << "\n" << ans.size() << "\n";
		for (int i = 0; i < (int) ans.size(); i++) {
			cout << ans[i].first << " = " << ans[i].second << "\n";
		}
	}
    return 0;
}
