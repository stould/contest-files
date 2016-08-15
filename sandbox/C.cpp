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

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 100005;
const Int INF = 1001001010000010LL;

int N;
Int P[MAXN];
string S[MAXN];
string R[MAXN];
Int dp[MAXN][3];
int mark[MAXN][3];

Int func(int pos, int is_last) {
    if (pos == N) {
        return 0;
    } else {
        Int& ans = dp[pos][is_last];

        if (!mark[pos][is_last]) {
            mark[pos][is_last] = true;

            ans = INF;

            if (pos == 0) {
                chmin(ans, func(pos + 1, 0));
                chmin(ans, P[pos] + func(pos + 1, 1));                    
            } else {
                if (is_last == 0) {
                    if (S[pos] >= S[pos - 1]) {
                        chmin(ans, func(pos + 1, 0));
                    }
                    if (R[pos] >= S[pos - 1]) {
                        chmin(ans, P[pos] + func(pos + 1, 1));
                    }
                } else {
                    if (S[pos] >= R[pos - 1]) {
                        chmin(ans, func(pos + 1, 0));
                    }
                    if (R[pos] >= R[pos - 1]) {
                        chmin(ans, P[pos] + func(pos + 1, 1));
                    }
                }
            }
        }

        return ans;
    }            
}

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        R[i] = S[i];

        reverse(R[i].begin(), R[i].end());
    }
    Int ans = func(0, 0);
    if (ans >= INF) ans = -1;
    cout << ans << endl;
    
    return 0;
}
