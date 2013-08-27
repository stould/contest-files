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

int A, R, T;
int runes[110][5];

int main(void) {
    freopen("i.in", "r", stdin);
    T = in();

    int i, j;

    for ( ; T--; ) {
        A = in(), R = in();

        int nr = 0, ir = 0, rr = 0;

        for (i = 0; i < R; i++) {
            int r_buff[110] = {0};
            for (j = 0; j < 4; j++) {
                runes[i][j] = in();

                if (runes[i][j] == 0 && j != 3) {
                    nr = 1;
                }
                if (abs(runes[i][j]) > A) {
                    ir = 1;
                }
                if (r_buff[abs(runes[i][j])] != 0) {
                    rr = 1;
                }
                r_buff[abs(runes[i][j])] = 1;
            }
        }

        if (nr) {
            puts("INVALIDO: ANEL NULO");
        } else if (ir) {
            puts("INVALIDO: ANEL FALTANTE");
        } else if (rr) {
            puts("INVALIDO: ANEL REPETIDO");
        } else {
            puts("OK");
        }
    }
    return 0;
}
