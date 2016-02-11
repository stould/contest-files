#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20020;

int T, N, K;
int id[MAXN];

int root(int i) {
	while(i != id[i]) {
		//id[i] = id[id[i]];
		i = id[i];
	}
	return i;
}

bool find(int p, int q) {
	return root(p) == root(q);
}


int main() {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> K;

		char C;
		int A, B, P;
    
		for (int i = 1; i <= N; i++) {
			id[i] = i;
		}

		for (int i = 1; i <= N; i++) {
			cin >> P;
      
			if (P != 0) {
				id[i] = P;
			}
		}

		cout << "Case #" << t << ":\n";

		for (int i = 0; i < K; i++) {
			cin >> C;
      
			if (C == 'Q') {
				cin >> A >> B;
	
				//cout << A << " = " << B << " => " << root(A) << " " << root(B) << "\n";
				if (find(A, B)) {
					cout << "YES\n";
				} else {
					cout << "NO\n";
				}
			} else {
				cin >> A;
				id[A] = A;
				//cout << A << " " << root(A) << "\n";
			}
		}
    
	}
	return 0;
}
