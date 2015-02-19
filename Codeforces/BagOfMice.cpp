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

const int MAXN = 1010;

int W, B;

double dp[MAXN][MAXN][2];
bool mm[MAXN][MAXN][2];

double func(int w, int b, int pos) {
    if (w == 0) {
        return 0.0;
    } else {
        double& ans = dp[w][b][pos];

        if (!mm[w][b][pos]) {
            mm[w][b][pos] = 1;

            if (pos == 0) {

            }
        }
    }
}

int main(void) {
    W = in();
    B = in();

    memset(mm, false, sizeof(mm));

    return 0;
}
