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

int H[5];
int T[5];

int winner(int a, int b, int casa) {
    int sa = H[a] + T[a];
    int sb = H[b] + T[b];

    if (sa == sb) {
        return casa;
    } else {
        if (sa > sb) {
            return a;
        } else {
            return b;
        }
    }
}

int main(void) {
    for (int i = 1; i <= 4; i++) {
        cin >> H[i] >> T[i];
    }

    int ia = winner(1, 2, 1);
    int ib = winner(3, 4, 3);

    if (ia == 1) {
        T[ib] += T[2];
    } else {
        T[ib] += T[1];
    }

    if (ib == 3) {
        T[ia] += T[4];
    } else {
        T[ia] += T[3];
    }

    cout << winner(ia, ib, ia) << "\n";
        
    return 0;
}
