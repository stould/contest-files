#include <bits/stdc++.h>

using namespace std;

int T, N, P, Q;
int B[110];

int main(void) {
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		cin >> N >> P >> Q;
		
		for (int i = 0; i < N; i++) {
			cin >> B[i];
		}
		
		sort(B, B + N);
		
		int ans = 0;
		int wei = 0;
		
		for (int i = 0; i < N; i++) {            
			if (ans + 1 <= P && wei + B[i] <= Q) {
				ans += 1;
				wei += B[i];
			}
		}
		cout << "Case " << t << ": " << ans << "\n";
	}
	return 0;
}
