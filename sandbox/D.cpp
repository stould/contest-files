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

int N, K;
double L, V1, V2;

int main(void) {
    cin >> N >> L >> V1 >> V2 >> K;

    double pos = 0.0;
    double ans = 0.0;

    while (N > 0) {
        double d1 = L - pos;

        ans += d1 / V2;
        N -= K;
        if (N <= 0) break;
        pos += V1 * (d1 / V2);

        double l = 0, h = 1000000000000, m;
        
        for (int i = 0; i < 500; i++) {
            m = (l + h) / 2.0;

            double p1 = pos + V1 * m;
            double p2 = L - V2 * m;

            if (p2 < p1) {
                h = m;
            } else {
                l = m;
            }
        }

        //cout << ans << endl;
        //cout << m << endl;        
        pos += V1 * m;
        ans += m;
        cout << ans << endl;
        if (pos >= L) break;
    }
    
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
