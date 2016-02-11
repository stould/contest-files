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

const int INF = INT_MAX / 4;

int N;
int P[1010];


int main(void) {
	cin >> N;

	for (int i = 0; i < 2 * N - 1; i++) {
		cin >> P[i];
	}

	int ans = accumulate(P, P + 2 * N - 1, 0);

	for (int x = 0; x < 5 * N; x++) {
		sort(P, P + 2 * N - 1);

		for (int i = 0; i < 2 * N - 1; i++) {
			cout << P[i] << " ";
		}

		cout << endl;

		for (int i = 0; i < N; i++) {
			P[i] = -P[i];
		}

		int buff = accumulate(P, P + 2 * N - 1, 0);

		chmax(ans, buff);
	}

	cout << ans << endl;

	return 0;
}
