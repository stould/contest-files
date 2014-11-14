#include <bits/stdc++.h>

using namespace std;

class LampsGrid {
public:
	int mostLit(vector <string>, int);
};

bool can(string line, int N, int K) {
	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		if (line[i] == '0') {
			ans += 1;
		}
	}
	
	if (ans <= K && (K - ans) % 2 == 0) {
		return true;
	} else {
		return false;
	}
}

int LampsGrid::mostLit(vector <string> initial, int K) {
	int N = (int) initial.size();
	int M = (int) initial[0].size();
	
	map<string, int> cnt;
	
	for (int i = 0; i < N; i++) {
		cnt[initial[i]] += 1;		
	}
	
	int ans = 0;
	
	for (const auto a: cnt) {
		if (can(a.first, M, K)) {
			ans = max(ans, a.second);
		}
	}
	
	return ans;
}

//Powered by [KawigiEdit] 2.0!
