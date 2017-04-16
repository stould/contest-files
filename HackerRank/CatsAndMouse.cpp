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

    for (int t = 1; t <= T; t++) {
        int x, y, z;
        cin >> x >> y >> z;

        int da = abs(x - z);
        int db = abs(y - z);

        if (da == db) {
            cout << "Mouse C" << endl;
        } else {
            if (da < db) {
                cout << "Cat A" << endl;
            } else {
                cout << "Cat B" << endl;
            }
        }
    }
    return 0;
}
