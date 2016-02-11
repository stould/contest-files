#include <bits/stdc++.h>

using namespace std;

int N, T, S;

int main() {
	cin >> N >> T >> S;

	for (int i = 0; i < N; i++) {
		int P;
    
		cin >> P;

		double sp = (T - (P - S)) / 2.0;

		cout << fixed << setprecision(6) << P + sp << "\n";
	}
	return 0;
}
