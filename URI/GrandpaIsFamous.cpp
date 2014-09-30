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

const int MAXN = 10005;

int N, M;
int S[MAXN];

int main(void) {
	for ( ; cin >> N >> M && !(N == 0 && M == 0); ) {
		int p;

		int best = -1;
		int second = -1;

		memset(S, 0, sizeof(S));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> p;
				
				S[p] += 1;

				if (S[p] > best) {
					second = best;
					best = S[p];
				}
			}
		}

		vector<int> cnt;

		for (int i = 1; i <= 10000; i++) {
			if (S[i] > 0) {
				cnt.push_back(S[i]);
			}
		}

		sort(cnt.begin(), cnt.end());

		second = cnt[cnt.size() - 2];

		for (int i = 1; i <= 10000; i++) {
			if (S[i] == second) {
				printf("%d ", i);
			}
		}
		printf("\n");
	}
    return 0;
}
