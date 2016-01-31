#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int N, S;
pair<int, int> P[MAXN];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) {
		return a.first > b.first;
	} else {
		return a.second < b.second;
	}
}	 

int main() {
	cin >> N >> S;

	int ans = 0;
	int fl = S;
  
	for (int i = 0; i < N; i++) {
		cin >> P[i].first >> P[i].second;
	}

	sort(P, P + N, cmp);

	for (int i = 0; i < N; i++) {
		ans += fl - P[i].first;

		ans = max(ans, P[i].second);
    
		fl = P[i].first;
	}

	ans += fl;
  
	cout << ans << "\n";
  
	return 0;
}
