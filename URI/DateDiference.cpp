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

int T;
int sy, sm, sd, ey, em, ed;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dp[35][15][3000];

int leap(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int main(void) {
    scanf("%d", &T);

    dp[1][1][1970] = 0;

    int py = 1970;
    int pm = 1;
    int pd = 1;
    
    for (int y = 1970; y <= 2014; y++) {
        for  (int m = 1; m <= 12; m++) {
            int day_cnt = days[m];

            if (m == 2 && leap(y)) {
                day_cnt += 1;
            }

            for (int d = 1; d <= day_cnt; d++) {
                dp[d][m][y] = 1 + dp[pd][pm][py];

                py = y;
                pm = m;
                pd = d;                
            }
        }
    }
    
    for ( ; T--; ) {
        scanf("%d-%d-%d %d-%d-%d", &ey, &em, &ed, &sy, &sm, &sd);

        if (ey < sy || (ey == sy && em < sm) || (ey == sy && em == sm && ed < sd)) {
            swap(ey, sy);
            swap(em, sm);
            swap(ed, sd);
        }
        
        int ans = dp[ed][em][ey] - dp[sd][sm][sy];
	
        printf("%d\n", ans);
    }
    return 0;
}
