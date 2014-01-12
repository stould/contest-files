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

int T;
int sx, sy, ex, ey;
string S;
int ans = -1;

int main(void) {

    cin >> T >> sx >> sy >> ex >> ey >> S;

    for (int i = 0; i < T; i++) {
        if (S[i] == 'N' && sy < ey) sy += 1;
        if (S[i] == 'S' && sy > ey) sy -= 1;
        if (S[i] == 'E' && sx < ex) sx += 1;
        if (S[i] == 'W' && sx > ex) sx -= 1;

        if (sx == ex && sy == ey) {
            ans = i + 1;
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}
