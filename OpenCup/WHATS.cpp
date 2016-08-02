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

const int MAXN = 110;

int PL, EL, T, P, A;
double PE;
int VP[MAXN];
double PR[MAXN][MAXN];
int DM[MAXN][MAXN];
double dp[MAXN][MAXN];
int memo[MAXN][MAXN];

double func(int pl, int el) {
    if (el <= 0) {
        return 1.0;
    } else if (pl <= 0) {
        return 0.0;
    } else {
        double& ans = dp[pl][el];

        if (memo[pl][el] == -1) {
            memo[pl][el] = 1;
            
            ans = 0;
            
            for (int i = 0; i < T; i++) {
                for (int j = 0; j < P; j++) {
                    double curr = 0;
                    double div = 0.0;                                    

                    for (int k = 0; k < (1 << VP[i]); k++) {
                        int damage = 0;
                        double prob = 1.0;
                        
                        for (int a = 0; a < VP[i]; a++) {
                            if (k & (1 << a)) {
                                damage += DM[i][j];
                                prob *= PR[i][j];
                            } else {
                                prob *= (1 - PR[i][j]);
                            }
                        }
                        
                        curr += prob * PE * func(pl - A, el - damage);                        
                        
                        if (damage > 0) {
                            curr += prob * (1 - PE) * func(pl, el - damage);
                        } else {
                            div += prob * (1 - PE);
                        }

                    }

                    curr /= (1 - div);                    
                    ans = max(ans, curr);

                    //double fail = 1.0;
                    
                    //for (int k = 0; k < VP[i]; k++) {
                    //fail *= (1 - PR[i][j]);
                    //}
                    //cout << ans << " " << fail << endl;
                    //ans /= (1 - fail);
                }
            }
            //ans += PE * PE * func(max(0, pl - A), max(0, el , turn ^ 1);
            //ans += (1 - PE) * func(pl, el, turn ^ 1);
            //ans += (1 - PE);
        }
        //cout << pl << " " << el << " " << ans << endl;
        return ans;
    }
}

int main(void) {
    freopen("whats.in", "r", stdin);
    freopen("whats.out", "w", stdout);
    cin >> PL >> EL >> T >> P;

    for (int i = 0; i < T; i++) {
        cin >> VP[i];

        for (int j = 0; j < P; j++) {
            cin >> PR[i][j] >> DM[i][j];
            
            PR[i][j] /= 100.0;
        }
    }

    cin >> PE >> A;

    PE /= 100.0;

    memset(memo, -1, sizeof(memo));
    
    cout << fixed << setprecision(16) << fabs(func(PL, EL)) << endl;
    
    return 0;
}
