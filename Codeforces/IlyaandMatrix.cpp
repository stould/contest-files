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

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 2000009;
int N, v[MAXN];
ll ans;

int main(void) {
    int i, j, k, l = 0;

    scanf("%d", &N);

    ans = 0LL;

    int _N = N;

    while (_N > 1) {
        l += 1;
        _N /= 4;
    }

    for (i = 0; i < N; i++) scanf("%d", &v[i]);

    if (N == 1) {
        printf("%d\n", v[0]); return 0;
    }

    ans = (ll) ((ll) accumulate(v, v + N, 0LL) * (ll) l);

    sort (v, v + N);

    for (i = N - 1, j = l; j > 0; i--, j--) {
        int x = N - 1;
        for (k = 0; k < j; k++) {
            ans += (ll) v[x--];
        }
    }

    printf("%I64d\n", ans < 0LL ? -ans : ans);

    return 0;
}
