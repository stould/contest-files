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

const int MAXN = 110;
const int INF = 10010100;

int N;
int A[MAXN];
int dp[MAXN][5];

int func(int pos, int last) {
    if (pos == N) {
        return 0;
    } else {
        int& ans = dp[pos][last];

        if (ans == -1) {
            ans = 1 + func(pos + 1, 0);

            if ((A[pos] == 2 || A[pos] == 3) && last != 1) {
                ans = min(ans, func(pos + 1, 1));
            }
            if ((A[pos] == 1 || A[pos] == 3) && last != 2) {
                ans = min(ans, func(pos + 1, 2));
            }
        }

        return ans;
    }
}

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << func(0, 0) << "\n";
    
    return 0;
}
