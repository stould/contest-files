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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 100005;
const double INF = 100000000000000000.0;

int N;
double AX, AY, BX, BY, TX, TY;
double X[MAXN], Y[MAXN];
double dp[MAXN][3][3];
bool seen[MAXN][3][3];

//last = 0 : not used
//last = 1 : used
//last = 2 : came home
double func(int pos, int lasta, int lastb) {
    if (pos >= N) {
        return lasta != 1 && lastb != 1 ? 0 : INF;
    }
    double& ans = dp[pos][lasta][lastb];

    if (!seen[pos][lasta][lastb]) {
        ans = INF;
        seen[pos][lasta][lastb] = true;

        double da = 0;
        double db = 0;

        if (lasta == 2) {
            da = 2 * hypot(X[pos] - TX, Y[pos] - TY);
            ans = min(ans, da + func(pos + 1, lasta, lastb));
        } else {
            da = 2 * hypot(X[pos] - TX, Y[pos] - TY);
            ans = min(ans, da + func(pos + 1, 1, lastb));
            
            da = hypot(AX - X[pos], AY - Y[pos]) + hypot(X[pos] - TX, Y[pos] - TY);
            ans = min(ans, da + func(pos + 1, 2, lastb));                      
        }
        if (lastb == 2) {
            db = 2 * hypot(X[pos] - TX, Y[pos] - TY);
            ans = min(ans, db + func(pos + 1, lasta, lastb));
        } else {
            db = 2 * hypot(X[pos] - TX, Y[pos] - TY);
            ans = min(ans, db + func(pos + 1, lasta, 1));
            
            db = hypot(BX - X[pos], BY - Y[pos]) + hypot(X[pos] - TX, Y[pos] - TY);
            ans = min(ans, db + func(pos + 1, lasta, 2));                      
        }
    }
    
    return ans;
}

/*
void rec(int pos, int lasta, int lastb) {
    if (pos >= N) return;

    double da = 0;
    double db = 0;
    
    if (lasta == 0) {
        da = hypot(AX - X[pos], AY - Y[pos]) + hypot(X[pos] - TX, Y[pos] - TY);
    } else {
        da = 2 * hypot(X[pos] - TX, Y[pos] - TY);
    }
    if (lastb == 0) {
        db = hypot(BX - X[pos], BY - Y[pos]) + hypot(X[pos] - TX, Y[pos] - TY);
    } else {
        db = 2 * hypot(X[pos] - TX, Y[pos] - TY);
    }
    
    double aa = da + func(pos + 1, 1, lastb);
    double bb = db + func(pos + 1, lasta, 1);

    if (da < db) {
        //cout << pos << " " << 0 << "\n";
        rec(pos + 1, 1, lastb);
    } else {
        //cout << pos << " " << 1 << "\n";
        rec(pos + 1, lasta, 1);
    }    
}

*/

int main(void) {
    cin >> AX >> AY >> BX >> BY >> TX >> TY >> N;

    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }
    
    memset(seen, false, sizeof(seen));

    //rec(0, 0, 0);
    
    cout << fixed << setprecision(12) << func(0, 0, 0) << "\n";
    
    return 0;
}
