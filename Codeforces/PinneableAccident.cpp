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

Int T, S, X;

int main(void) {
    cin >> T >> S >> X;
    
    Int G1 = (X - T) / S;
    Int M1 = (X - T) % S;
    Int G2 = (X - T - 1) / S;
    Int M2 = (X - T - 1) % S;
    
    if (M1 == 0 && T + G1 * S == X && G1 >= 0) {        
        cout << "YES\n";
    } else if (M2 == 0 && G2 > 0 && T + G2 * S + 1 == X) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}
