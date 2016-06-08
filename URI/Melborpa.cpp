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

int N;
Int dp[20][11][3];
bool s[20][11][3];

Int func(int pos, int last, int seen, int lpos) {
    if (s[pos][last][seen]) return dp[pos][last][seen];
    if (pos > lpos) {
        return seen ? 1LL : 0LL;            
    } else if (pos == lpos) {
        return seen ? 10LL : 0LL;
    } else {
        Int& ans = dp[pos][last][seen];

        if (ans == -1) {
            ans = 0LL;
        }

        return ans;
    }
}

int main(void) {
    cin >> N;

    cout << func(1, 0, false, N) << "\n";
    return 0;
}
