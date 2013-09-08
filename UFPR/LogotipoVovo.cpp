#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

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

int X, Y, K, N, M, T = 1;

int nd[15][15];
int ha[350][350];

int main(void) {
    int i, j, k, l;

    for ( ; scanf("%d%d", &X, &Y) == 2 && X + Y != 0; ) {
        for (i = 0; i < X; i++) {
            for (j = 0; j < Y; j++) {
                nd[i][j] = in();
            }
        }

        K = in(), M = in(), N = in();

        int ans = 0;

        for ( ; K--; ) {
            for (i = 0; i < M; i++) {
                for (j = 0; j < N; j++) {
                    ha[i][j] = in();
                }
            }
            int ok = 0;

            for (i = 0; i < M; i++) {
                for (j = 0; j < N; j++) if (ha[i][j] == nd[0][0]) {
                    int match = 1;

                    for (k = 0; k < X; k++) {
                        for (l = 0; l < Y; l++) {
                            if (!match) goto o;

                            match &= (ha[i+k][j+l] == nd[k][l]);
                        }
                    }
                    o:;

                    if (match) {
                        ok += 1;
                    }
                }
            }

            end:;

            if (ok) ans += ok;
        }

        printf("Logotipo %d\n%d\n\n", T++, ans);
    }
    return 0;
}
