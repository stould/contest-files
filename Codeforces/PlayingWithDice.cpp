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

int A, B;

int main(void) {
    cin >> A >> B;

    int a = 0, b = 0, c = 0;

    for (int i = 1; i <= 6; i++) {
        int da = abs(i - A);
        int db = abs(i - B);

        if (da < db) {
            a += 1;
        } else if (da == db) {
            b += 1;
        } else {
            c += 1;
        }
    }

    cout << a << " " << b << " " << c << "\n";

    return 0;
}
