#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

int N, M;
int A[1005], B[10005];

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A + N);

	bool ok = true;

	for (int i = 0; i < M; i++) {
		cin >> B[i];

		if (!binary_search(A, A + N, B[i])) {
			bool found = false;

			int pl = 0, pr = i - 1;

			while (pl <= pr) {
				int sum = B[pl] + B[pr];
				if (sum == B[i]) {
					found = true;
					break;
				} else if (sum > B[i]) {
					pr -= 1;
				} else {
					pl += 1;
				}
			}
			
			if (!found) {				
				cout << B[i] << "\n";
				ok = false;
				break;
			}
		}
		
		int j = i;

		while (j >= 1 && B[j] < B[j - 1]) {
			swap(B[j], B[j - 1]);
			j--;
		}
	}

	if (ok) {
		cout << "sim\n";
	}
	
    return 0;
}
