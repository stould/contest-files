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
double dp[MAXN][MAXN][2][2][110];
int memo[MAXN][MAXN][2][2][110];
int id = 1;
vector<int> wheel = {20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5};

double func(int sa, int sb, int now, int st, int depth) {
    if (depth >= 50) {
        return 0.0;
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
        double& ans = dp[sa][sb][now][st][depth];

        if (memo[sa][sb][now][st][depth] != id) {
            memo[sa][sb][now][st][depth] = id;

            //double rev = 0.0;
            double ia = 0;
            double mb = 1000000.0;
            
            for (int i = 0; i < (int) wheel.size(); i++) {                
                if (now == 0) {
                    if (sa - wheel[i] >= 0) {
                        ia += func(sa - wheel[i], sb, now ^ 1, st, depth + 1);
                    } else {
                        ia += func(sa, sb, now ^ 1, st, depth + 1);
                    }
                } else {
                    double curr_prob = 0.0;
                    
                    for (int j = -1; j <= 1; j++) {
                        int curr = (i + j) % 20;
                        
                        if (sb - wheel[curr] >= 0) {
                            curr_prob += func(sa, sb - wheel[curr], now ^ 1, st, depth + 1);
                        } else {
                            curr_prob += func(sa, sb, now ^ 1, st, depth + 1);
                        }
                    }
                    
                    mb = min(mb, curr_prob);
                }
            }
            cout << sa << " " << sb << " " << depth << " " << ia << endl;
            if (now == 0) {
                ans = 1 - ia / 20.0;
            } else {
                ans = 1 - mb / 3.0;
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
