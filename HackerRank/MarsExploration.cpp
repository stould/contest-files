#include <bits/stdc++.h>

using namespace std;

string S;

int main() {
	cin >> S;

	int ans = 0;

	for (int i = 0; i + 2 < (int) S.size(); i += 3) {
		if (S[i] != 'S') ans += 1;
		if (S[i + 1] != 'O') ans += 1;
		if (S[i + 2] != 'S') ans += 1;
	}
	cout << ans << "\n";
	return 0;
}
