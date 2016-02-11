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
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 50050;

int N, K;
int P[MAXN];

int main(void) {
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	sort(P, P + N);

	Int l = 1, h = 1000000000LL, m;
	Int best = -1;

	while (l <= h) {
		m = (l + h) / 2;
		
		int used = 0;

		for (int i = 0; i < N; i++) {
			int j = i;

			used += 1;

			while (j < N && P[j] <= P[i] + 2 * m) {
				j += 1;
			}

			i = j - 1;
		}

		if (used <= K) {
			h = m - 1;
			best = m;
		} else {
			l = m + 1;
		}
	}

	cout << best << endl;

	return 0;
}
