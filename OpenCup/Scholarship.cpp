#include <bits/stdc++.h>

using namespace std;

int N;
int P[15];
int cnt[15];

int main() {
	cin >> N;

	double A = 0.0;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
		cnt[P[i]] += 1;
		A += P[i];
	}

	A /= (double) N;

	if (cnt[3] > 0) {
		cout << "None\n";
	} else {
		if (cnt[5] == N) {
			cout << "Named\n";
		} else if (A >= 4.5) {
			cout << "High\n";
		} else {
			cout << "Common\n";
		}
	}

  
	return 0;
}
