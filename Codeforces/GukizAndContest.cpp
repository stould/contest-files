#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2020;

int N;
int A[MAXN];

bool sortA(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

bool sortB(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

int main(void) {
	cin >> N;

	vector<pair<int, int> > vp(N);

	for (int i = 0; i < N; i++) {
		vp[i].first = i;
		cin >> vp[i].second;
	}
  
	sort(vp.begin(), vp.end(), sortA);

	for (int i = 0; i < N; i++) {
		int j = i + 1;
		for ( ; j < N && vp[j].second == vp[i].second; ) {
			j += 1;
		}
		vp[i].second = 1 + (N - j);
	}

	sort(vp.begin(), vp.end(), sortA);
  
	vector<int> ans(N);

	int pos = N;

	for (int i = 0; i < N; i++) {
		if (i > 0 && vp[i].second == vp[i - 1].second) {
			ans[vp[i].first] = ans[vp[i - 1].first];
		} else {
			ans[vp[i].first] = pos;
		}
		pos -= 1;
	}

	for (int i = 0; i < N; i++) {
		cout << N - ans[i] + 1 << " ";
	}
	cout << "\n";
  
	return 0;
}
