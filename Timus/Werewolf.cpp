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

int N, P;
string S;
vector<pair<int, int> > graph[1010];
bool vis[1010];

vector<int> split(string st) {
	vector<int> ans;
	istringstream ss(st);
	int buff;

	for ( ; ss >> buff; ) {
		ans.push_back(buff);
	}

	return ans;
}

int dfs(int x, int kind) {
	vis[x] = true;

	for (int i = 0; i < (int) graph[x].size(); i++) {
		int u = graph[x][i].first;
		int t = graph[x][i].second;

		if (!vis[u] && kind == t) dfs(u, kind);
	}	
}

int main(void) {
	cin >> N;
	cin.ignore();

	for ( ; getline(cin, S) && S[0] != 'B'; ) {
		vector<int> vi = split(S);

		//1 = parent, 2 = son
		graph[vi[0]].push_back(make_pair(vi[1], 1));
		graph[vi[1]].push_back(make_pair(vi[0], 2));
	}

	for ( ; cin >> P; ) {
		dfs(P, 1);
		dfs(P, 2);
	}

	bool has = false;
	
	for (int i = 1; i <= N; i++) {
		if (!vis[i]) {
			has = true;
			cout << i << " ";
		}
	}
	
	if (!has) cout << "0";

	cout << "\n";

    return 0;
}
