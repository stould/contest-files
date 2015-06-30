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

const int MAXN = 1000005;
const double EPS = 1e-9;

Int N, W;
Int A[MAXN];

int main(void) {
    cin >> N >> W;

    for (int i = 0; i < 2 * N; i++) {
        cin >> A[i];
    }

    sort(A, A + 2 * N);
    
    double l = 0, h = 1000000000.0, m;
    double ans = 0.0;
    
    for (int i = 0; i < 300; i++) {
        m = (l + h) / 2;
        
        if (N * m + 2 * N * m + EPS <= W) {
            if (m + EPS <= A[0]) {
                if (2.0 * m + EPS <= A[N]) {
                    ans = max(ans, N * m + 2 * N * m);
                    l = m;
                } else {
                    h = m;
                }
            } else {
                h = m;
            }
        } else {
            h = m;
        }
    }
    
    cout << fixed << setprecision(10) << ans <<"\n";
    
    return 0;
}
