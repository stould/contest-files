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
char cs[25][25];

int main(void) {
    freopen("i.in", "r", stdin);
    freopen("o.ot", "w", stdout);
    cin >> T;

    int a;
    int b;
    int i, j, k;
    int x;

    for (x = 1; x <= T; x++) {
        cin >> N;

        int cnt = 0;

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                cin >> cs[i][j];

                if (cs[i][j] == '#') {
                    cnt += 1;
                }
            }
        }

        bool ok = false;

        for (i = 0; i < N; i++) {
            for (j = i; j < N; j++) {
                for (k = 0; k + i < N && k + j < N; k++) {
                    int now = 0;
                    bool all = true;

                    for (a = 0; a <= k; a++) {
                        for (b = 0; b <= k; b++) {
                            now += (cs[i + a][j + b] == '#');
                            all &= (cs[i + a][j + b] == '#');
                        }
                    }

                    if (now == cnt && all) {
                        ok = true;
                        break;
                    }
                }
            }
        }
        printf("Case #%d: %s\n", x, ok ? "YES" : "NO");
    }

    return 0;
}
