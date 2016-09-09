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

class EmoticonsDiv2 {
public:
    int printSmiles(int);
};

const int INF = INT_MAX / 3;

int dp[1010][1010];

int func(int s, int c, int t) {
    if (s > t) {
        return INF;
    } else if (s == t) {
        return 0;
    } else {
        int& ans = dp[s][c];
		
        if (ans == -1) {
            ans = INF;
			
            ans = min(ans, 1 + func(s, s, t));
            ans = min(ans, 1 + func(s + c, c, t));
        }
		
        return ans;
    }
}

int EmoticonsDiv2::printSmiles(int smiles) {
    memset(dp, -1, sizeof(dp));
    return func(1, 0, smiles);
}

   //Powered by [KawigiEdit] 2.0!
