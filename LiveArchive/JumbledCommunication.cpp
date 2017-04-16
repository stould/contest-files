#include <bits/stdc++.h>

using namespace std;

long long N, P;

int main() {
    while (cin >> N) {
	for (int i = 0; i < N; i++) {
            cin >> P;

            for (int j = 0; j <= 256; j++) {
                long long val = j ^ (j << 1LL);

                for (int k = 8; k <= 32; k++) {
                    val &= ~(1LL << k);
                }
      
                if (val == P) {
                    cout << j << " ";
                    break;
                }
            }    
	}
	cout << "\n";
    }
    return 0;
}
