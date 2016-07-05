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

const int MAXN = 1010;
const int INF = INT_MAX / 4;

int T, N;
int V[11];
string S;
int dp[MAXN][12][12];

int main(void) {
	cin >> T;

	for ( ; T--; ) {
		for (int i = 0; i <= 9; i++) {
			cin >> V[i];
		}
		cin >> N >> S;
		
		while (1) {
			bool seen = false;
			
			for (int i = 0; i <= 9; i++) {
				for (int j = 0; j <= 9; j++) {
					for (int k = 0; k <= 9; k++) {
						if (i == (j + k) % 10 && V[i] > V[j] + V[k]) {
							V[i] = V[j] + V[k];
							seen = true;
						}
					}

				}
			}
			if (!seen) break;
		}

		int ans = 0;
		
		for (int i = 0; i < N; i++) {
			ans += V[S[i] - '0'];
		}
		
		cout << ans << "\n";
	}
	return 0;
}
