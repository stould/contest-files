#include <bits/stdc++.h>

using namespace std;

int N, M;

int main(void) {
	for ( ; cin >> N && N != 0; ) {
		int A = 0;
		int B = 0;
		int tmp;

		for (int i = 0; i < N; i++) {
			cin >> tmp;
			A += tmp;
		}

		cin >> M;

		for (int i = 0; i < M; i++) {
			cin >> tmp;
			B += tmp;
		}

		if (A > B) {
			cout << 1 << "\n";
		} else if (B > A) {
			cout << 2 << "\n";
		} else {
			cout << "Sem vencedor\n";
		}
	}
	return 0;
}
