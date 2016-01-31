#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
	while (cin >> N && N != 0) {
		vector<int> ps(1500, 0);
    
		for (int i = 0; i < N; i++) {
			int buff;
			cin >> buff;
			ps[buff] += 1;
		}
    
		bool ok = true;

		int pos = 0, fuel = 0;

		while (pos <= 1422) {
			if (fuel < 0) {
				ok = false;	
			}
			if (ps[pos]) {
				fuel = 200;
			}
			fuel -= 1;
			pos += 1;
		}

		pos = 1422;

		while (pos >= 0) {
			if (fuel < 0) {
				ok = false;	
			}
			if (ps[pos]) {
				fuel = 200;
			}
			fuel -= 1;
			pos -= 1;
		}
    
		if (ok) {
			cout << "POSSIBLE\n";
		} else {
			cout << "IMPOSSIBLE\n";
		}
	}  
	
	return 0;
}
