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

using namespace std;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

Int M;

int main(void) {
    cin >> M;

    Int l = 1LL, h = 100000000000000000L, m;
    Int ans = -1;

    while (l <= h) { 
        m = l + (h - l) / 2;

        Int ways = 0;

        for (Int i = 2; ; i++) {
            if (i * i * i > m) break;
            ways += m / (i * i * i);
        }

        if (ways == M) {
            ans = m;
            h = m - 1;
        } else if (ways > M) {
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
