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

int N;
int F[5], M[5];

bool func1(int a, int b, int c) {
    int i;
    bool ok;

    ok = false;
    for (i = -2; i <= 2; i++) {
        int ni = ((((a + i) % N) + N) % N);

        if (ni == F[0]) ok = true;
    }
    if (!ok) return false;

    ok = false;
    for (i = -2; i <= 2; i++) {
        int ni = ((((b + i) % N) + N) % N);

        if (ni == F[1]) ok = true;
    }
    if (!ok) return false;

    ok = false;
    for (i = -2; i <= 2; i++) {
        int ni = ((((c + i) % N) + N) % N);

        if (ni == F[2]) ok = true;
    }
    if (!ok) return false;

    return true;
}

bool func2(int a, int b, int c) {
    int i;
    bool ok;

    ok = false;
    for (i = -2; i <= 2; i++) {
        int ni = ((((a + i) % N) + N) % N);

        if (ni == M[0]) ok = true;
    }
    if (!ok) return false;

    ok = false;
    for (i = -2; i <= 2; i++) {
        int ni = ((((b + i) % N) + N) % N);

        if (ni == M[1]) ok = true;
    }
    if (!ok) return false;

    ok = false;
    for (i = -2; i <= 2; i++) {
        int ni = ((((c + i) % N) + N) % N);

        if (ni == M[2]) ok = true;
    }
    if (!ok) return false;

    return true;
}

int main(void) {
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
    int i;
    int j;
    int k;

    N = in();

    for (i = 0; i < 3; i++) {
        F[i] = in();
    }
    for (i = 0; i < 3; i++) {
        M[i] = in();
    }

    int ans = 0;

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            for (k = 1; k <= N; k++) {
                if (func1(i, j, k) || func2(i, j, k)) {
                    //printf("%d %d %d\n", i, j, k);
                    ans += 1;
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}

