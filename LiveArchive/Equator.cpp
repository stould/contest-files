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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned uint;

const int MAXN = 2000005;

int T, N;
int P[MAXN];

int main(void) {
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> P[i];
			P[i + N] = P[i];
		}

		int best = 0;
		int curr = 0, len = 0;

		for (int i = 0; i < 2 * N; i++) {
			cout << P[i] << " ";
		}
		cout << "\n";
		for (int i = 0; i < 2 * N; i++) {
			curr += P[i];

			if (curr < 0) {
				curr = 0;
				len = 0;
			} else {
				len += 1;
			}
			if (len > N) {
				curr -= P[i - N];
			}
			cout << i << " " << len << " " << curr << "\n";
			chmax(best, curr);
		}
		cout << best << "\n";
	}
	return 0;
}
