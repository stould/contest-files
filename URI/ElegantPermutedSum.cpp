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

int T;
int N;
int S[MAXN];

int main(void) {
	T = in();
	
	for (int t = 1; t <= T; t++) {
		N = in();

		for (int i = 0; i < N; i++) {
			S[i] = in();
		}

		printf("Case %d: ", t);

		sort(S, S + N);
		
		vector<int> sp(N);
		int sa = N / 2, pa = N - 1;
		int sb = (N + 1) / 2, pb = 0;

		for (int i = 0; i < N / 2; i++) {
			if (sa >= 0) {
				if (pa % 2 == 0) {
					sp[pa] = S[sa];
					sa -= 1;
				} else {
					sp[pa] = S[sb];
					sb += 1;
				}
				sa -= 1;
				pa -= 1;
			}
			if (sb < N) {
				if (pb % 2 == 1) {
					sp[pb] = S[sb];
					sb += 1;
				} else {
					sp[pb] = S[sa];
					sa -= 1;
				}
				pb += 1;
			}
		}
		
		int ans = 0;
		
		for (int i = 1; i < N; i++) {
			//cout << sp[i] << " ";
			ans += abs(sp[i] - sp[i - 1]);
		}						
		printf("\n%d\n", ans);		
	}
    return 0;
}
