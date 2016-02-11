#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

string A, B;
int N, M;

long long SA[MAXN];
long long SB[MAXN];

int main() {
	cin >> A >> B;

	N = (int) A.size();
	M = (int) B.size();

	long long ans = 0;

	for (int i = M - 1; i >= 0; i--) {
		SA[i] = B[i] == '0';
		SB[i] = B[i] == '1';

		SA[i] += SA[i + 1];
		SB[i] += SB[i + 1];
	}
  
	int pos = 0;
  
	for (int i = N - 1; i >= 0; i--) {
		if (A[i] == '0') {
			ans += SB[i] - SB[M - pos++];
		} else {
			ans += SA[i] - SA[M - pos++];
		}
	}
  
	cout << ans << "\n";
  
	return 0;
}
