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

int A, B, C, D;
string SA, SB, SC, SD;
int dp[30][3][3][3][3];

int main(void) {
    cin >> A >> B >> C >> D;

    Int ans = 0LL;
    
    for (int i = 1; i <= A; i++) {
        for (int j = 1; j <= B; j++) {
            memset(dp, -1, sizeof(dp));

            ans += func(0, 0, 0, true, true);
        }
    }

    
    return 0;
}
