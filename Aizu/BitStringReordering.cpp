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

int func(vector<int> A, vector<int> B) {
	int ans = 0;
	
	vector<int> cntA(2, 0), cntB(2, 0);

	for (int i = 0; i < A.size(); i++) {
		cntA[A[i]] += 1;
	}
	for (int i = 0; i < B.size(); i++) {
		cntB[B[i]] += 1;
	}

	if (cntA[0] != cntB[0] || cntA[1] != cntB[1]) {
		return 100101010;
	}

	for (int i = 0; i < B.size(); i++) {
		if (A[i] != B[i]) {
			for (int j = i + 1; j < B.size(); j++) {
				if (A[i] == B[j]) {
					while (j != i) {
						swap(B[j], B[j - 1]);
						j -= 1;
						ans += 1;
					}
					break;
				}
			}
		}
	}

	return ans;
}

int main(void) {
	cin >> N >> M;

	vector<int> P(N), A, B;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	for (int i = 0; i < M; i++) {
		int c;
		cin >> c;

		for (int j = 0; j < c; j++) {
			A.push_back(i % 2);
		}
	}
	for (int i = 0; i < A.size(); i++) {
		B.push_back(A[i] ^ 1);
	}

	int ans = min(func(P, A), func(P, B));

	cout << ans << "\n";
    return 0;
}
