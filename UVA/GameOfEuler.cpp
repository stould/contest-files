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

int T;
vector<string> S(4);
int dp[1 << 16];
vector<int> all_masks;

void reset() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			S[i][j] = '.';
		}
	}
}

int to_mask(const vector<string>& vs) {
	int ans = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (vs[i][j] == 'X') {
				ans |= (1 << (4 * i + j));
			}
		}
	}

	return ans;
}

int func(int mask) {
	if (mask == (1 << 16) - 1) {
		return 1;
	} else {
		int& ans = dp[mask];
		
		if (ans == -1) {
			ans = 0;

			for (int i = 0; i < (int) all_masks.size(); i++) {
				if (!(mask & all_masks[i])) {
					if (!func(mask | all_masks[i])) {
						ans = 1;
					}
				}
			}

		}
		return ans;
	}		
}

int main(void) {
	cin >> T;

	for (int i = 0; i < 16; i++) {
		all_masks.push_back(1 << i);
	}

	for (int i = 0; i < 4; i++) {
		S[i] = string(4, '.');
	}

	for (int i = 0; i < 4; i++) {
		reset();	
		for (int j = 0; j < 3; j++) {			
			S[i][j] = 'X';
			if (j > 0) {
				all_masks.push_back(to_mask(S));
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		reset();	
		for (int j = 0; j < 3; j++) {			
			S[j][i] = 'X';
			if (j > 0) {
				all_masks.push_back(to_mask(S));
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		reset();	
		for (int j = 0; j < 3; j++) {			
			S[i][3 - j] = 'X';
			if (j > 0) {
				all_masks.push_back(to_mask(S));
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		reset();	
		for (int j = 0; j < 3; j++) {			
			S[3 - j][i] = 'X';
			if (j > 0) {
				all_masks.push_back(to_mask(S));
			}
		}
	}

	memset(dp, -1, sizeof(dp));
	
	for (int t = 1; t <= T; t++) {
		int base = 0;
		
		for (int i = 0; i < 4; i++) {
			cin >> S[i];
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (S[i][j] == 'X') {
					base |= (1 << (4 * i + j));
				}
			}
		}

		if (func(base)) {
			cout << "WINNING\n";
		} else {
			cout << "LOSING\n";
		}
	}
	
	return 0;
}
