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

	int i;
	int x;

	for (x = 1; x <= T; x++) {
		N = in();

		for (i = 0; i < N; i++) {
			S[i] = in();
		}

		printf("Case %d: ", x);

		if (N == 1) {
			printf("%d\n", S[0]);
		} else {
			sort(S, S + N);

			vector<int> sp;
			swap(S[0], S[1]);

			int ans = 0;

			for (i = 0; i < N / 2; i++) {
				sp.push_back(S[i]);
				sp.push_back(S[N - i - 1]);				
			}

			//if (N % 2 == 0) N--;
			//printf("%d\n", N);
			for (i = 0; i < N - 1; i++) {
				//printf("%d ", sp[i]);
				ans += abs(sp[i] - sp[i + 1]);
			}			
			//printf("\n");
			printf("%d\n", ans);
		}
	}
    return 0;
}