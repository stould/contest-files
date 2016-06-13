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

int T, N;
int dp[1010][5];

int func(int val, int cnt) {
    if (cnt == 0) {
        return val == 0 ? 1 : 0;
    } else {
        int& ans = dp[val][cnt];

        if (ans == -1) {
            ans = 0;

            for (int i = 1; i * (i + 1) / 2 <= val; i++) {
                if (func(val - i * (i + 1) / 2, cnt - 1)) {
                    ans = 1;
                    break;
                }
            }
        }

        return ans;
    }
}

int main(void) {
    cin >> T;

    memset(dp, -1, sizeof(dp));
    
    while (T--) {
        cin >> N;
        cout << (func(N, 3) ? "1" : "0") << "\n";
    }
    return 0;
}
