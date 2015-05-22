#include <bits/stdc++.h>

using namespace std;

int K;
string S;

int main(void) {
	while (cin >> K >> S) {
		int N = (int) S.size();
		
		if (K > N) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for (int i = 0; i < N - K - 1; i++) {
				cout << S[i] << "\n";
			}
			cout << S.substr(K, N - K) << "\n";
		}
	}
	
    return 0;
}
