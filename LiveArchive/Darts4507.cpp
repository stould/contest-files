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

const int MAXN = 505;
int N;
double dp[MAXN][MAXN][2][2];
int memo[MAXN][MAXN][2][2];
int id = 1;
vector<int> wheel = {20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5};

double func(int sa, int sb, int now, int st, int depth) {
    if (depth >= 5000) {
        return 1.0;
    } else if (sa == 0 || sb == 0) {
        if (sa == 0) {
            if (st == 0) {
                return 1.0;
            } else {
                return 0.0;
            }
        } else {
            if (st == 1) {
                return 1.0;
            } else {
                return 0.0;
            }
        }
    } else {
        double& ans = dp[sa][sb][now][st];

        if (memo[sa][sb][now][st] != id) {
            memo[sa][sb][now][st] = id;
            
            ans = 0.0;
            
            //double rev = 0.0;
            double ia = 0;
            double fb = 10000000.0;
            double mb = 0.0;
            
            for (int i = 0; i < (int) wheel.size(); i++) {                
                if (now == 0) {
                    if (sa - wheel[i] >= 0) {
                        ia += func(sa - wheel[i], sb, now ^ 1, st, depth + 1);
                    } else {
                        ia += func(sa, sb, now ^ 1, st, depth + 1);
                        //rev = (1.0 / (double) wheel.size());
                    }
                } else {
                    if (sb - wheel[i] >= 0) {
                        fb = min(fb, (1.0 / 3.0) * func(sa, sb - wheel[i], now ^ 1, st, depth + 1));
                        mb = max(mb, (1.0 / 3.0) * func(sa, sb - wheel[i], now ^ 1, st, depth + 1));
                    } else {
                        fb = min(fb, (1.0 / 3.0) * func(sa, sb, now ^ 1, st, depth + 1) / 3.0);
                        mb = max(mb, (1.0 / 3.0) * func(sa, sb, now ^ 1, st, depth + 1) / 3.0);
                        //ans += func(sa, sb, now ^ 1, st, depth + 1);
                        //rev = (1.0 / 3.0);
                    }
                }
            }
            if (st == 0) {
                if (now == 0) {
                    ans = 1 - ia / 20.0;
                } else {
                    ans = fb;
                }
            } else {
                if (now == 1) {
                    ans = 1 - mb;
                } else {
                    ans = ia / 20.0;
                }
            }
        }

        return ans;
    }
}

int main(void) {
    while (cin >> N && N != 0) {
        double sa = func(N, N, 0, 0, 0);
        double sb = func(N, N, 1, 1, 0);

        cout << fixed << setprecision(8) << sa << " " << sb << "\n";
        id++;
    }
    return 0;
}
