#include <bits/stdc++.h>

using namespace std;

int T, N, K;
int P[110];

int main() {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
    
		for (int i = 0; i < N; i++) {
			cin >> P[i];
		}

		sort(P, P + N);

		int ans = 0;

		for (int i = 0; i < N; i++) {
			ans += 1;

			int j = i + 1;

			while (j < N && P[j] - P[j - 1] <= K) {
				j += 1;
			}

			i = j - 1;
		}

		cout << "Case #" << t << ": " << ans << "\n";
	}
	return 0;
}
