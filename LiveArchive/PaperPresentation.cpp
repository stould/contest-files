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

int T, N;
char str[20][20];
int x[20];

int main(void) {
    freopen("i.in", "r", stdin);
    T = in();

    int i;
    int j;

    for ( ; T--; ) {
        N = in();

        for (i = 0; i < 2 * N; i++) {
            x[i] = i;
            scanf("%s", str[i]);
        }
        int ans = 0;

        do {
            bool ok = true;
            for (i = 0; i < 2 * N && ok; i++) {
                for (j = 0; j < i && ok; j++) {
                    if (str[i][j] == 'Y') ok = false;
                }
            }
            if (ok) ans += 1;
        } while (next_permutation(x, x + (2 * N)));

        printf("%d\n", ans);
    }

    return 0;
}

