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
typedef unsigned long long uInt;
typedef unsigned uint;

int N, M;
int P[60][60];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector<pair<int, int> > q[1000010];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (abs(a.first) != abs(b.first)) {
		return abs(a.first) < abs(b.first);
	} else {
		return abs(a.second) < abs(b.second);
	}		  
}

uInt getHash(vector<pair<int, int> > arg) {
	uInt ans = 10000007ULL;

	for (int i = 0; i < (int) arg.size(); i++) {
		ans = ans * 1234567891 + abs(arg[i].first) + 1074178147781ULL;
        ans = ans * 1234567891 + abs(arg[i].second) + 1074178147781ULL;
	}
	
	return ans;
}

vector<vector<pair<int, int> > > generatePoly(int len) {
	vector<vector<pair<int, int> > > ans;

	int qf = 0, qt = 0;

	vector<pair<int, int> > base;
	base.push_back(make_pair(0, 0));
	q[qt++] = base;
	
	map<uInt, bool> vis;
	
	for ( ; qf < qt; ) {
		//cout << qf << " " << qt << endl;
		vector<pair<int, int> > now = q[qf++];

		if (len == (int) now.size()) {
			ans.push_back(now);
			continue;
		}
		
		for (int i = 0; i < (int) now.size(); i++) {
			for (int j = 0; j < 4; j++) {
				int now_i = now[i].first + dx[j];
				int now_j = now[i].second + dy[j];

				if (now_i < 0) continue;

				pair<int, int> curr = make_pair(now_i, now_j);
				
				if (find(now.begin(), now.end(), curr) == now.end()) {
					vector<pair<int, int> > poss = now;
					
					poss.push_back(curr);
					sort(poss.begin(), poss.end(), cmp);

					uInt c_hash = getHash(poss);
					
					if (vis[c_hash] == false) {
						vis[c_hash] = true;
						q[qt++] = poss;
					}
				}														   
			}
		}
	}

	return ans;
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;

	vector<vector<pair<int, int> > > poly = generatePoly(M);
	//cout << poly.size() << endl;
	/*
	for (int i = 0; i < (int) poly.size(); i++) {
		vector<string> check;
		
		for (int k = 0; k < 7; k++) {
			check.push_back("##########");
		}
		
		for (int j = 0; j < (int) poly[i].size(); j++) {
			cout << poly[i][j].first << " " << poly[i][j].second << endl;
			int ni = 3 + poly[i][j].first;
			int nj = 3 + poly[i][j].second;

			if (ni >= 0 && nj >= 0 && ni < 10 && nj < 10) {
				check[ni][nj] = '$';
			} else {
				assert(false);
			}
		}
		for (int j = 0; j < 7; j++) {
			cout << check[j] << endl;
		}
		cout << endl;
		cout << endl;
	}
	*/
	int ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> P[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < (int) poly.size(); k++) {
				int in = 0;
				int sum = 0;

				for (int a = 0; a < (int) poly[k].size(); a++) {
					int ni = i + poly[k][a].first;
					int nj = j + poly[k][a].second;

					if (ni >= 0 && nj >= 0 && ni < N && nj < N) {
						in += 1;

						sum += P[ni][nj];
					} else {
						break;
					}
				}
				
				if (in == M) {
					chmax(ans, sum);
				}
			}
		}
	}

	cout << ans << endl;
	
	return 0;
}
