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
int d[10];

int main(void) {
    N = in();

    int i, j;

    for (i = 0; i < N; i++) {
        d[in()] += 1;
    }

    if (d[0] == 0 || (d[0] == 0 && d[5] < 9)) {
        printf("-1");
    } else {
        int cnt = (int) floor((double) d[5] / 9.0);

        bool ok = 0;

        for (i = 0; i < cnt; i++) {
            for (j = 0; j < 9; j++) {
                printf("5");
                ok = 1;
            }
        }

        if (!ok) {
            printf("0\n");
        } else {
            for (i = 0; i < d[0]; i++) {
                printf("0");
            }
            printf("\n");
        }
    }

    return 0;
}
