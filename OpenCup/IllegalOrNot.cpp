#include <bits/stdc++.h>

using namespace std;

int N, A, B;
bool seen[2020];

int main() {
	cin >> N;

	bool ok = false;

	memset(seen, 0, sizeof(seen));
  
	for (int i = 0; i < N; i++) {
		cin >> A >> B;

		for (int j = A; j <= B; j++) {
			seen[j] = true;
		}
	}

	for (int i = 1; i + 180 <= 1827; i++) {
		int cnt = 0;

		for (int j = 0; j < 180; j++) {
			cnt += (seen[i + j] == true);
		}
		if (cnt > 90) {
			ok = true;
			break;
		}
	}

	if (ok) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
	}
	return 0;
}
