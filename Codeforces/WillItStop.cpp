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

void func(Int x) {
    while (x > 1) {
        cout << x << endl;
        if (x % 2 == 0) {
            x /= 2;
        } else {
            x = 3 * x + 3;
        }
    }
}

int main(void) {
    cin >> N;
    
    if (__builtin_popcountll(N) == 1) {
        cout << "TAK" << endl;
    } else {
        cout << "NIE" << endl;
    }
    return 0;
}
