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

int main(void) {
    cin >> T;

    while (T--) {
        int now;

        Int in = 0;
        Int outside = 0;
        
        while (cin >> now && now != 0) {
            if (now != 1) {
                outside += max(0LL, now - in * 2LL);
            }
            in = now;
        }

        cout << outside << "\n";
    }
    return 0;
}
