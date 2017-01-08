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

int T;
int H, S;

int num, den;

void rec(int x, int y, char d, int z, int run, int val) {
    if (run == x) {
        den += 1;
        
        if (z != -1) {
            if (d == '+') {
                val += z;
            } else {
                val -= z;
            }            
        }
        if (val >= H) {
            num += 1;
        }
    } else {
        for (int i = 1; i <= y; i++) {
            rec(x, y, d, z, run + 1, val + i);
        }
    }
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> H >> S;

        cout << "Case #" << t << ": ";

        double ans = 0.0;
        
        for (int i = 0; i < S; i++) {
            string S;
            cin >> S;

            int x = -1;
            int y = -1;
            int z = -1;
            
            char d, dummy;
            //cout << S;
            sscanf(S.c_str(), "%2i%c%d%c%d", &x, &dummy, &y, &d, &z);
            
            //cout << x << " " << dummy << " " << y << " " << d << " " << z << endl;

            num = 0;
            den = 0;
            
            rec(x, y, d, z, 0, 0);

            chmax(ans, num / (double) den);
        }
        
        cout << fixed << setprecision(6) << ans << endl;
    }
    return 0;
}
