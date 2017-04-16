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


int A, B;

int main(void) {
    cin >> A >> B;

    if (A <= 0 && B >= 0) {
        cout << "Zero" << endl;
    } else {
        if (A < 0) {
            int cnt = abs(A);
            if (B < 0) {
                cnt -= abs(B) + 1;
            }
            if (cnt % 2 == 0) {
                cout << "Positive" << endl;
            } else {
                cout << "Negative" << endl;
            }
        } else {
            cout << "Positive" << endl;
        }
    }
    return 0;
}




