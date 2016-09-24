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

class RepeatStringEasy {
public:
    int maximalLength(string);
};
const int MAXN = 60;

string A, B;
int dp[MAXN][MAXN];

int func(int a, int b) {
    if (a == A.size() || b == B.size()) {
        return 0;
    } else {
        int& ans = dp[a][b];
		
        if (ans == -1) {
            ans = 0;
			
            ans = max(ans, func(a + 1, b));
            ans = max(ans, func(a, b + 1));
			
            if (A[a] == B[b]) {
                ans = max(ans, 1 + func(a + 1, b + 1));
            }
        }
		
        return ans;
    }
	
}

int RepeatStringEasy::maximalLength(string s) {
    int ans = 0;
    int N = s.size();
	
    for (int i = 0; i < N; i++) {
        A = s.substr(0, i);
        B = s.substr(i, N - i);
        memset(dp, -1, sizeof(dp));
        ans = max(ans, 2 * func(0, 0));
    }
	
    return ans;
}
//Powered by [KawigiEdit] 2.0!
