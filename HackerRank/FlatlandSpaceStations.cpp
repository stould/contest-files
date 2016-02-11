#include <bits/stdc++.h>

using namespace std;

int N, M;
int C[100005];
int P[100005];

int L[100005];
int R[100005];

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> C[i];
		P[C[i]] = 1;
	}

	L[0]     = P[0] ? 0 : 10000000;
	R[N - 1] = P[N - 1] ? 0 : 10000000;
  
	for (int i = 1; i < N; i++) {
		if (P[i]) {
			L[i] = 0;
		} else {
			L[i] = L[i - 1] + 1;
		}
	}
	for (int i = N - 2; i >= 0; i--) {
		if (P[i]) {
			R[i] = 0;
		} else {
			R[i] = R[i + 1] + 1;
		}
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		ans = max(ans, min(L[i], R[i]));
	}

	cout << ans << "\n";
  
	return 0;
}
