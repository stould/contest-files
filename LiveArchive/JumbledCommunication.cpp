#include <bits/stdc++.h>

using namespace std;

int N, P;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P;

		for (int j = 0; j <= 255; j++) {
			int val = j ^ (j << 1);

			for (int k = 8; k <= 31; k++) {
				val &= ~(1 << k);
			}
      
			if (val == P) {
				cout << (int) j << " ";
				break;
			}
		}    
	}
	cout << "\n";
    
	return 0;
}
