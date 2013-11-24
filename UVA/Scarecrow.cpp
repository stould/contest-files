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

int N, T;
char str[110];

int main(void) {
    T = in();

    int x;
    int i;

    for (x = 1; x <= T; x++) {
        N = in();
        scanf("%s", str);

        int ans = 0;

        for (i = 0; i < N; i++) {
            if (str[i] == '.') {
                ans += 1;
                i += 2;
            }
        }

        printf("Case %d: %d\n", x, ans);
    }

    return 0;
}
