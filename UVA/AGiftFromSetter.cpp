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

const int MAXN = 400005;
const Int MOD = 1000007LL;
int T, N;
Int K, C;
Int A[MAXN];

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> K >> C >> N >> A[0];

		for (int i = 1; i < N; i++) {
			A[i] = (K * A[i - 1] + C) % MOD;
			A[i] = ((A[i] % MOD) + MOD) % MOD;
		}
		sort(A, A + N);
		Int ans = 0LL;
		Int sum = A[N - 1];
		
		for (int i = N - 2; i >= 0; i--) {
			Int P = (N - i - 1) * A[i];

			ans += abs(P - sum);
			
			sum += A[i];
		}

		cout << "Case " << t << ": " << ans << "\n";
	}
	return 0;
}
