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

Int N;

int func(Int x) {
    int ans = 0;

    while (x > 0) {
        ans += (x % 10);
        x /= 10;
    }
    
    return ans;
}

int main(void) {
    cin >> N;

    int ans = 0;
    Int a = 0, b = 0;

    if (N < 10) {
        ans = N;
        a = 0;
        b = N;
    } else {
        Int base = 9;
        
        while (base <= N) {            
            if (func(base) + func(N - base) > ans) {
                ans = func(base) + func(N - base);
                a = base;
                b = N - a;
            }
            base = base * 10 + 9;
        }
    }
    
    cout << ans << "\n" << a << " " << b << "\n";
    return 0;
}
