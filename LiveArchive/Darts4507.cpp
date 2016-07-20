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
double dp[MAXN][MAXN][2];
int memo[MAXN][MAXN][2];
int id = 1;
vector<int> wheel = {20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5};

double func(int sa, int sb, int now) {
    if (sa == 0) {
        return 1;
    } else if (sb == 0) {
        return 0;
    } else {
        double& ans = dp[sa][sb][now];

        if (memo[sa][sb][now] != id) {
            memo[sa][sb][now] = id;

            //double rev = 0.0;
            double ia = 0;
            double mb = 1000000.0;
            double dv = 0.0;

            for (int i = 0; i < (int) wheel.size(); i++) {                
                if (now == 0) {
                    if (sa - wheel[i] >= 0) {
                        ia += (1.0 / 20.0) * func(sa - wheel[i], sb, now ^ 1);
                    } else {
                        dv += (1.0 / 20.0);
                    }
                } else {
                    double curr_prob = 0.0;
                    double div = 0.0;

                    for (int j = -1; j <= 1; j++) {
                        int curr = (i + j + 20) % 20;

                        if (sb - wheel[curr] >= 0) {
                            curr_prob += (1.0 / 3.0) * func(sa, sb - wheel[curr], now ^ 1);
                        } else {
                            div += (1.0 / 3.0);
                        }
                    }
                    curr_prob /= (1 - div);
                    mb = min(mb, 1 - curr_prob);
                }
            }
            ia /= (1 - dv);
            
            //cout << sa << " " << sb << " " << ia << " " << dv << endl;
            if (now == 0) {
                ans = fabs(1 - ia);
            } else {
                ans = mb;
            }
        }

        return ans;
    }
}

int main(void) {
    while (cin >> N && N != 0) {
        double sa = func(N, N, 0);
        double sb = 0;

        cout << fixed << setprecision(8) << sa << " " << sb << "\n";
        id++;
    }
    return 0;
}
