#include <bits/stdc++.h>

using namespace std;

int N;
int P[15];

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	vector<int> good;
  
	for (int x = -100000; x <= 100000; x++) {
		int df = x;

		for (int i = 0; i < N; i++) {
			df = abs(df - P[i]);
		}

		if (df <= 1) {
			good.push_back(x);
		}
	}

	vector<pair<int, int> > ans;
  
	for (int i = 0; i < (int) good.size(); i++) {
		int l = good[i];
		int r = good[i];
    
		int j = i + 1;
    
		while (j < (int) good.size()) {
			if (good[j] != good[j - 1] + 1) break;
			r = good[j];
			j += 1;
		}

		ans.push_back(make_pair(l, r));
    
		i = j - 1;    
	}

	cout << ans.size() << "\n";

	for (int i = 0; i < (int) ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
	return 0;
}
