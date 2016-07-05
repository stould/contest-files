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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 140;

int M, N;
string S[MAXN];
int P[MAXN];
int ans;

void bt(int mask, int val, vector<vector<int> > groups) {
	if (N == (int) groups.size()) {
		ans = min(ans, val);
	} else if (val >= ans) {
		return;
	} else {
		for (int i = 0; i < M; i++) {
			if (!(mask & (1 << i))) {
				vector<vector<int> > vg;
				
				for (int j = 0; j < (int) groups.size(); j++) {
					vector<int> sa, sb;
					
					for (int k = 0; k < (int) groups[j].size(); k++) {
						if (groups[j][k] & (1 << i)) {
							sa.push_back(groups[j][k]);
						} else {
							sb.push_back(groups[j][k]);
						}
					}
					
					if (!sa.empty()) vg.push_back(sa);
					if (!sb.empty()) vg.push_back(sb);
				}				
				
				if (vg.size() > groups.size()) {
					bt(mask | (1 << i), val + 1, vg);
				}
			}
		}
	}
}


int main(void) {
	while (cin >> M >> N && N + M != 0) {
		for (int i = 0; i < N; i++) {
			cin >> S[i];

			P[i] = 0;

			for (int j = 0; j < M; j++) {
				if (S[i][j] == '1') {
					P[i] |= (1 << j);
				}
			}
		}

		ans = 100;

		vector<vector<int> > groups(1, vector<int>());
		
		for (int i = 0; i < N; i++) {
			groups[0].push_back(P[i]);
		}
		
		bt(0, 0, groups);
		
		cout << ans << endl;
	}
	return 0;
}
