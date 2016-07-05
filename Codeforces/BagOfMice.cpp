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
    if (pos == 0) {
        if (w <= 0) {
            return 0;
        } else if (b <= 0) {
            return 1;
        }
    } else {
        if (w <= 0 or b <= 0) {
            return 0;
        }
    }
        
    double& ans = dp[w][b][pos];
    
    if (mm[w][b][pos] == false) {
        mm[w][b][pos] = true;

        ans = 0;

        double all = w + b;
            
        if (pos == 0) {
            ans += (w / all);
            ans += (b / all) * func(w, b - 1, pos ^ 1);                
        } else {
            ans += (b / all) * ((b - 1) / (all - 1)) * func(w, b - 2, pos ^ 1);
            ans += (b / all) * (w / (all - 1)) * func(w - 1, b - 1, pos ^ 1);
        }
    }
        
    return ans;
}

int main(void) {
    W = in();
    B = in();

    memset(mm, false, sizeof(mm));

    cout << fixed << setprecision(9) << func(W, B, 0) << endl;
    
    return 0;
}
