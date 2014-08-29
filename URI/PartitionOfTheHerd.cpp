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

const int MAXN = 1010;

int N, P[MAXN];

int func(int a, int b) {
	int ans = 0; 

	for (int i = a; i < b; i++) {
		for (int j = i + 1; j <= b; j++) {
			ans += abs(P[i] - P[j]);
		}
	}

	return ans;
}

int main(void) {
	for ( ; scanf("%d", &N) == 1; ) {				
		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
		}

		sort(P, P + N);

		int b = -1, e = -2;

		for (int i = 0; i < N; i++) {
			int j = i + 1;
			while (j < N && P[i] == P[j]) {
				j += 1;
			}
			if (j != i + 1) {
				if (j - i > e - b) {
					b = i;
					e = j - 1;
				}
			}
			i = j - 1;
		}
		int ans = INT_MAX;

		if (b != -1) {
			vector<int> vs;
			for (int i = 0; i <= b - 1; i++) {
				vs.push_back(P[i]);
			}
			for (int i = e + 1; i < N; i++) {
				vs.push_back(P[i]);
			}
			for (int i = 0; i < (int) vs.size(); i++) {
				P[i] = vs[i];
			}
			N = (int) vs.size();
			ans = func(0, N - 1);
		} else {
			int A = 0, B = 0;
			A = func(0, N / 2 - 1) + func(N / 2, N - 1);
			B = func(0, N / 2) + func(N / 2 + 1, N - 1);
			ans = min(A, B);
		}

		printf("%d\n", ans);
		
	}
    return 0;
}
