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

int N, K;

int func(int K) {
    int cnt = 0;
    int occur[10] = {0};

    int i;

    for (i = 1; i <= K; i++) {
        Int x = (Int) ((Int) i * (Int) N);

        while (x > 0LL) {
            if (!occur[x % 10LL]) {
                occur[x % 10LL] = 1;
                cnt += 1;

                if (cnt == 10) return 1;
            }
            x /= 10LL;
        }
    }

    return 0;
}

int main(void) {
    for ( ; scanf("%d", &N) == 1; ) {
        int l = 1, h = 10000, m;
        int ans = 10000000;

        while (l <= h) {
            m = (l + h) / 2;

            int res = func(m);

            if (res) {
                ans = min(ans, m);
                h = m - 1;
            } else {
                l = m + 1;
            }

        }

        printf("%d\n", ans);
    }
    return 0;
}

