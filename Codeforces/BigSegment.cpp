#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int N, L[MAXN], R[MAXN];

int main(void) {
	cin >> N;

	int ML = INT_MAX, MR = -1;

	for (int i = 0; i < N; i++) {
		cin >> L[i] >> R[i];

		ML = min(ML, L[i]);
		MR = max(MR, R[i]);
	}

	for (int i = 0; i < N; i++) {
		if (L[i] == ML && R[i] == MR) {
			cout << i + 1 << "\n";
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}
