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
double dp[MAXN][MAXN][2][150];
int memo[MAXN][MAXN][2][150];
int id = 1;
vector<int> wheel = {20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5};

double func(int sa, int sb, int now, int level) {
    if (level > 100) return 0;
    if (sa == 0) {
        return 1;
    } else if (sb == 0) {
        return 0;
    } else {
        double ans = dp[sa][sb][now][level];

        if (memo[sa][sb][now][level] != id) {
            memo[sa][sb][now][level] = id;

            ans = 0;

            if (now == 0) {
                double ia = 0;
                
                for (int i = 0; i < (int) wheel.size(); i++) {                
                    if (sa - wheel[i] >= 0) {
                        ia += func(sa - wheel[i], sb, now ^ 1, level + 1);
                    } else {
                        ia += func(sa, sb, now ^ 1, level + 1);
                    }
                }
                ia /= 20.0;
                //cout << ia << " " << div << endl;
                ans = ia;
            } else {
                ans = 1000;
                
                double curr_prob = 0.0;
                double end_prob = 10000;
                
                for (int i = 0; i < (int) wheel.size(); i++) {                                      
                    for (int j = -1; j <= 1; j++) {
                        int curr = (i + j + 20) % 20;

                        if (sb - wheel[curr] >= 0) {
                            curr_prob += func(sa, sb - wheel[curr], now ^ 1, level + 1);
                        } else {
                            curr_prob += func(sa, sb, now ^ 1, level + 1);
                        }
                    }
                    curr_prob /= 3;
                    chmin(end_prob, curr_prob);
                }
                ans = 1 - end_prob;
            }
        }
        
        return ans;
    }
}

int main(void) {
    while (cin >> N && N != 0) {
        double sa = func(N, N, 0, 0);
        double sb = 0;

        cout << fixed << setprecision(8) << sa << " " << sb << "\n";
        id++;
    }
    return 0;
}
