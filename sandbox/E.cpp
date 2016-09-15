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
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 3030;
const Int INF = 100010010010100LL;

int N;
Int P[MAXN];
unordered_map<Int, Int> dp[MAXN];

Int func(int pos, Int curr) {
    if (pos == N) {
        return 0;
    } else {
        if (dp[pos].find(curr) == dp[pos].end()) {
            dp[pos][curr] = INF;
            
            Int l = curr + 1, h = 10000000005;
            Int nextL = INF;
            
            for (int i = 0; i < 40; i++) {
                Int m = (l + h) / 2;
                
                nextL = abs(P[pos + 1] - m) + func(pos + 1, m);    
                
                if (nextL >= dp[pos][curr]) {
                    l = m + 1;
                } else {
                    h = m - 1;
                }
                
                dp[pos][curr] = min(dp[pos][curr], nextL);
            }
        }
        
        return dp[pos][curr];
    }
}

int main(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }

    Int ans = func(0, 0);

    cout << ans << "\n";
    return 0;
}
