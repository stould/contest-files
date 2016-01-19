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

const int MAXN = 100010;

int T, N;
Int P, B[MAXN];

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> P;

		for (int i = 0; i < N; i++) {
			cin >> B[i];
		}

		Int ans = 0LL, sum = 0LL;
		int b = 0;
		
		for (int i = 0; i < N; i++) {
			sum += B[i];
			
			while (sum > P && b < i) {
				sum -= B[b];
				b += 1;
			}

			if (sum <= P) {
				ans += i - b + 1;
			}
		}
		
		cout << "Case #" << t << ": " << ans << "\n";
	}
	return 0;
}
