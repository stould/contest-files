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

int N;
string A;

int func(string A, string B) {
    int i;
    int d = 0;

    if (A.size() != B.size()) return 100;

    for (i = 0; i < (int) A.size(); i++) {
        d += (A[i] != B[i]);
    }
    return d;
}

int main(void) {
    N = in();

    for ( ; N--; ) {
        cin >> A;

        if (func(A, "one") <= 1) {
            cout << 1;
        } else if (func(A, "two") <= 1) {
            cout << 2;
        } else if (func(A, "three") <= 1) {
            cout << 3;
        }
        cout << "\n";
    }

    return 0;
}
