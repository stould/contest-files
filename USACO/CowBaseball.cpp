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

const int MAXN = 1010;

int N;
int P[MAXN];

int bs_f(int l, int h, int target, int start) {
    int m;
    int iter = -1;

    for ( ; l <= h; ) {
        m = (l + h) / 2;

        if (P[m] - start >= target) {
            iter = m;
            h = m - 1;
        } else {
            l = m + 1;
        }
    }

    return iter;
}

int bs_s(int l, int h, int target, int start) {
    int m;
    int iter = -1;

    for ( ; l <= h; ) {
        m = (l + h) / 2;

        if (P[m] - start <= target) {
            iter = m;
            l = m + 1;
        } else {
            h = m - 1;
        }
    }

    return iter;
}


int main(void) {
    freopen("baseball.in", "r", stdin);
    freopen("baseball.out", "w", stdout);
    N = in();

    int i;
    int j;

    for (i = 0; i < N; i++) P[i] = in();

    sort(P, P + N);

    int ans = 0;

    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            int l = bs_f(j + 1, N - 1, P[j] - P[i], P[j]);
            int u = bs_s(j + 1, N - 1, 2 * (P[j] - P[i]), P[j]);

            if (l != -1 && u != -1) {
                ans += u - l + 1;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
