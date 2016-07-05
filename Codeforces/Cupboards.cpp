#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;

int N, L[MAXN], R[MAXN];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> L[i] >> R[i];
	}
  
	int A = accumulate(L, L + N, 0);
	int B = accumulate(R, R + N, 0);
  
	cout << min(A, N - A) + min(B, N - B) << "\n";
	return 0;
}
