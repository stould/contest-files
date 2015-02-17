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

string D;

int main(void) {
    for ( ; cin >> D; ) {
        int h, m, s;

        sscanf(D.c_str(), "%d:%d:%d", &h, &m, &s);

        printf("%d\n", (24 * 60 * 60) - ((60 * h + m) * 60 + s));
    }
    return 0;
}
