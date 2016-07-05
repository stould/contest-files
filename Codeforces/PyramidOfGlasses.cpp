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

const double EPS = 1e-9;

int N, T;
double P[15][15];
int reach[15][15];

Int mypow(Int base, Int exp) {
    Int ans = 1LL;

    for (int i = 0; i < exp; i++) {
        ans *= base;
    }
    
    return ans;
}

int main(void) {
    cin >> N >> T;

    for (int x = 1; x <= T; x++) {
        P[0][0] += 1;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++) {
                if (P[i][j] > 1.0) {
                    double rest = P[i][j] - 1.0;

                    P[i][j] = 1.0;

                    P[i + 1][j]     += rest / 2.0;
                    P[i + 1][j + 1] += rest / 2.0;
                }
            }
        }
    }

    int zr = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (fabs(P[i][j] - 1) < EPS) {
                zr += 1;
            }
        }
    }
    cout << zr << "\n";
    
    /*
    P[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            P[i + 1][j]     += mypow(2, i + 1);
            P[i + 1][j + 1] += mypow(2, i + 1);

            reach[i + 1][j] += 1;
            reach[i + 1][j + 1] += 1;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (reach[i][j] > 1) {
                P[i][j] = mypow(2, i) / reach[i][j];
            }
        }        
    }
    
    int zr = 0;
    
    for (int x = 1; x <= 20; x++) {
        bool vis[20][20];
        
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++) {
                if (vis[i][j]) continue;
                
                if (P[i][j] == 1) {
                    P[i][j] = 0;
                    zr += 1;

                    if (!vis[i + 1][j]) {
                        vis[i + 1][j] = true;
                        P[i + 1][j] /= 2;
                    }
                    if (!vis[i + 1][j + 1]) {
                        vis[i + 1][j + 1] = true;
                        P[i + 1][j + 1] /= 2;
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++) {
                cout << P[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        //cout << x << " " << zr << "\n";
    }    
    */
    return 0;
}
