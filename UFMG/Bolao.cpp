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

int P, N;
int poss[15][15][2];
int resu[15][2];
string name[15];

bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second != b.second) {
		return a.second > b.second;
	} else {
		return a.first < b.first;
	}
}

int main(void) {
	for ( ; cin >> P >> N && !(P == 0 && N == 0); ) {
		string ta, tb;
		
		for (int i = 0; i < P; i++) {
			cin >> name[i];
			
			for (int j = 0; j < N; j++) {
				cin >> ta >> poss[i][j][0] >> tb >> poss[i][j][1];
			}
		}
		for (int i = 0; i < N; i++) {
			cin >> ta >> resu[i][0] >> tb >> resu[i][1];
		}

		vector<pair<string, int> > vp;
		
		for (int i = 0; i < P; i++) {
			int pt = 0;
			

			for (int j = 0; j < N; j++) {
				int rp = (poss[i][j][0] > poss[i][j][1] ? 0 : poss[i][j][0] < poss[i][j][1] ? 1 : 2);
				int sq = (resu[j][0] > resu[j][1] ? 0 : resu[j][0] < resu[j][1] ? 1 : 2);
				
				if (poss[i][j][0] == resu[j][0] && poss[i][j][1] == resu[j][1]) {
					pt += 10;
				} else if (rp == sq && (poss[i][j][0] == resu[j][0] || poss[i][j][1] == resu[j][1])) {
					pt += 7;
				} else if (rp == sq) {
					pt += 5;
				} else if (poss[i][j][0] == resu[j][0] || poss[i][j][1] == resu[j][1]) {
					pt += 2;
				}
			}

			vp.push_back(make_pair(name[i], pt));
		}

		sort(vp.begin(), vp.end(), cmp);

		for (int i = 0; i < P; i++) {
			cout << vp[i].first << " " << vp[i].second << "\n";
		}
	}
    return 0;
}
