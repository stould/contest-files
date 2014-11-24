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

string A, B;
int N, L;
map<int, string> up;
map<string, int> id;
vector<int> graph[MAXN];
bool vis[MAXN], mat[MAXN][MAXN], cls[MAXN][MAXN];

int fix(string s) {
	if (!id[s]) {
		id[s] = L;
		up[L] = s;
		L++;		
	}
	return id[s];
}

int main(void) {
	int test = 1;
	for ( ; cin >> N && N != 0; ) {
		if (test > 1) cout << "\n";
		L = 1;
		id.clear();
		up.clear();

		for (int i = 0; i < MAXN; i++) {
			for (int j = 0; j < MAXN; j++) {
				mat[i][j] = cls[i][j] = false;
			}
		}

		for (int i = 0 ; i < N; i++) {
			cin >> A >> B;			
			cls[fix(A)][fix(B)] = mat[fix(A)][fix(B)] = true;
		}

		vector<pair<string, string> > ans;

		for (int k = 1; k < L; k++) {
			for (int i = 1; i < L; i++) {
				for (int j = 1; j < L; j++) {
					mat[i][j] |= (mat[i][k] & mat[k][j]);
				}
			}
		}

		for (int i = 1; i < L; i++) {
			for (int j = 1; j < L; j++) {
				if (cls[i][j]) {
					for (int k = 1; k < L; k++) {
						if (mat[i][k] && mat[k][j]) {
							cls[i][j] = false;
							ans.push_back(make_pair(up[i], up[j]));
							break;
						}
					}
				}
			}
		}
		
		cout << "Case " << test++ << ": " << ans.size();

		if (!ans.empty()) {
			sort(ans.begin(), ans.end());

			for (int i = 0; i < (int) ans.size(); i++) {
				cout << " " << ans[i].first << "," << ans[i].second;
			}
		}
	}
    return 0;
}
