#include <bits/stdc++.h>

using namespace std;

int N;
string S;
int cnt[3];

int id(char s) {
	if (s == 'R') return 0;
	if (s == 'S') return 1;
	return 2;
}

int win(char s) {
	if (s == 'R') return 1;
	if (s == 'S') return 2;
	return 0;
}

int main(void) {
	for ( ; cin >> N && N != 0; ) { 
		cin >> S;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < N; i++) {
			cnt[id(S[i])] += 1;
		}

		for (int i = 0; i < N; i++) {
			if (i > 0) cout << " ";
			long long ans = cnt[id(S[i])] - 1 + 3 * cnt[win(S[i])];

			cout << ans;
		}
		cout << "\n";
	}
	return 0;
}
