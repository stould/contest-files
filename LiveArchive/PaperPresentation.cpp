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
int fat[20];

int main(void) {
    freopen("i.in", "r", stdin);
    T = in();

    int i;
    int j;

    fat[1] = 1;

    for (int i = 2; i < 20; i++) {
        fat[i] = i * fat[i - 1];
    }

    for ( ; T--; ) {
        N = in();

        int ans = 0;

        for (i = 0; i < 2 * N; i++) {
            scanf("%s", str[i]);
        }

        set<int> f;

        for (int i = 0; i < 2 * N; i++) {
            for (int j = i + 1; j < 2 * N; j++) {
                if (str[i][j] == 'Y') {
                   f.insert(i);
                   f.insert(j);
                }
            }
        }

        printf("\n%d\n", f.size());
    }

    return 0;
}

