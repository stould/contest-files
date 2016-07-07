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

const int MAXN = 5005;

string S;
Int dp[MAXN];

Int func(int pos) {
    if (pos >= (int) S.size()) {
        return 1LL;
    } else if (S[pos] == '0') {
        return 0LL;
    } else {
        Int& ans = dp[pos];

        if (ans == -1) {
            ans = 0;
			
            int curr = 0;

            for ( ; pos < S.size(); ) {
                curr = curr * 10 + (S[pos] - '0');
                if (curr > 26) break;
                ans += func(pos + 1);
                pos++;
            }
        }
		
        return ans;
    }
}

int main(void) {
    while (cin >> S && S != "0") {
        memset(dp, -1LL, sizeof(dp));
        cout << func(0) << endl;
    }
    return 0;
}
