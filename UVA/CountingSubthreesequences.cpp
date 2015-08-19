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

const int MAXN = 1000005;

string S;
int N;

int dp[4];

int main(void) {
	for ( ; cin >> S; ) {
		Int ans = 0, curr = 0;
		
		for (int i = 0; i < (int) S.size(); i++) {
			if (S[i] >= '0' && S[i] <= '9') {
				curr = curr * 10 + (S[i] - '0');
				curr = ((curr % 3) + 3) % 3;

				if (curr == 0) {
					ans += 1;
				}
				
				ans += dp[curr];			
				dp[curr] += 1;
			} else {
				memset(dp, 0, sizeof(dp));
				curr = 0;
			}
		}		
		cout << ans << "\n";
	}
    return 0;
}
