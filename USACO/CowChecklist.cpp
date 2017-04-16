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

const int MAXN = 1010;
const Int INF = 1001001001001LL;

int H, G;
int HX[MAXN], HY[MAXN];
int GX[MAXN], GY[MAXN];

Int dp[MAXN][MAXN][2];
bool vis[MAXN][MAXN][2];

Int pw(Int arg) {
    return arg * arg;
}

Int func(int ih, int ig, int kind) {
    if (ih == H && ig == G) {
        if (kind == 0) {
            return 0;
        } else {
            return pw(GX[ig] - HX[ih]) + pw(GY[ig] - HY[ih]);
        }
    } else {
        Int& ans = dp[ih][ig][kind];

        if (!vis[ih][ig][kind]) {
            vis[ih][ig][kind] = true;

            ans = INF;
            
            if (ih + 1 <= H) {
                Int dst = 0;

                if (kind == 0) {
                    dst = pw(HX[ih] - HX[ih + 1]) + pw(HY[ih] - HY[ih + 1]);
                } else {
                    dst = pw(GX[ig] - HX[ih + 1]) + pw(GY[ig] - HY[ih + 1]);
                }

                ans = min(ans, dst + func(ih + 1, ig, 0));
            }
            if (ig + 1 <= G) {
                Int dst = 0;
                
                if (kind == 0) {
                    dst = pw(HX[ih] - GX[ig + 1]) + pw(HY[ih] - GY[ig + 1]);
                } else {
                    dst = pw(GX[ig] - GX[ig + 1]) + pw(GY[ig] - GY[ig + 1]);
                }

                ans = min(ans, dst + func(ih, ig + 1, 1));
            }
        }
        
        return ans;
    }
}

int main(void) {
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
    
    cin >> H >> G;

    for (int i = 1; i <= H; i++) {
        cin >> HX[i] >> HY[i];
    }
    for (int i = 1; i <= G; i++) {
        cin >> GX[i] >> GY[i];
    }
    
    memset(vis, false, sizeof(vis));

    cout << func(1, 0, 0) << "\n";
    return 0;
}
