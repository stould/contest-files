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

using namespace std;

typedef long long ll;
typedef unsigned uint;

const int MAXN = 60;
int N, R;
int v[MAXN];

int func (void) {
    int i;
    int m = INT_MIN, l = 0, h = 0;

    int curr = 0;

    for (i = 0; i < N; i++) {
        curr += v[i] - R;

        if (curr > m) {
            m = curr;
            h = i;
        }

        if (curr < 0) {
            curr = 0;
            l = i + 1;
        }
    }

    return m < 0 ? 0 : m;
}

int main(void) {
    int i;
    for ( ; scanf("%d%d", &N, &R) == 2; ) {
        for (i = 0; i < N; i++) {
            scanf("%d", &v[i]);
        }

        printf("%d\n", func());
    }
    return 0;
}
