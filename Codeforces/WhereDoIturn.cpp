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

const double PI = acos(-1.0);
int P[3][2];

int main(void) {
    freopen("i.in", "r", stdin);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> P[i][j];
        }
    }

    int atb = (int) atan2(P[1][1] - P[0][1], P[1][0] - P[0][0]) * 180.0 / PI;
    int btc = (int) atan2(P[2][1] - P[1][1], P[2][0] - P[1][0]) * 180.0 / PI;

    //atb = ((atb % 360) + 360) % 360;
    //btc = ((btc % 360) + 360) % 360;

    if (atb == btc) {
        puts("TOWARDS");
    } else {
        cout << atb << " " << btc << "\n";
    }

    return 0;
}
