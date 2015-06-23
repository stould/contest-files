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

const int MAXN = 5050;

int N;
string A, B;
vector<int> graph[MAXN];
int prv[MAXN];

int main(void) {
	cin >> N;

	map<string, int> ori;
	map<int, string> toi;
	int id = 1;
	
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		
		if (ori[A] == 0) {
			ori[A] = id;
			toi[id] = A;
			id++;
		}
		if (ori[B] == 0) {
			ori[B] = id;
			toi[id] = B;
			id++;
		}
		graph[ori[A]].push_back(ori[B]);
		prv[ori[B]] = ori[A];
	}

	vector<pair<string, string> > ans;
	
	for (int i = 1; i < id; i++) {
		if (graph[i].size() == 0) {
			B = toi[i];
			int p = i;
			
			while (prv[p] != 0) {
				p = prv[p];
			}
			ans.push_back(make_pair(toi[p], B));
		}
	}
	cout << ans.size() << endl;

	for (int i = 0; i < (int) ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}
