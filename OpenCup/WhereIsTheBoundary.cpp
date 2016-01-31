#include <bits/stdc++.h>

using namespace std;

int N, M;
string S;

int main(){
	while (cin >> N >> M && N != 0) {  
		long long best = 0;
		int st = -1;

		vector<long long> sW(N + 1, 0), sE(N + 1, 0);
    
		for (int x = 0; x < M; x++) {
			cin >> S;

			for (int i = 0; i < N; i++) {
				sE[i] += (S[i] == 'E');
				sW[i] += (S[i] == 'W');	
			}
		}
      
		for (int i = 1; i < N; i++) {
			sW[i] += sW[i - 1];
		}
		for (int i = N - 2; i >= 0; i--) {
			sE[i] += sE[i + 1];
		}
      
		for (int i = 0; i < N; i++) {
			long long curr = sW[i] + sE[i + 1];

			if (curr > best) {
				best = curr;
				st = i;
			}      
		}

		if (best <= sE[0]) {
			st = -1;
		}
    
		cout << st + 1 << " " << st + 2 << "\n";
	}
	return 0;
}
