#include <bits/stdc++.h>

using namespace std;

long long N;

int main(void) {
	cin >> N;

	N -= 1;

	vector<int> ans;
  
	for (int i = 1; i <= (long long) sqrt(N); i++) {
		if (N % i == 0) {
			ans.push_back(i);

			if (i * i != N) {
				ans.push_back(N / i);
			}
		}
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < (int) ans.size(); i++) {
		cout << ans[i] << " ";
	}
  
	cout << "\n";
  
	return 0;
}
