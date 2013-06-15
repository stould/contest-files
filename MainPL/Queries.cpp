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

int N, a, b, d;

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d", &N);

    int i, j;

    for ( ; N--; ) {
        scanf("%d%d%d", &a, &b, &d);

        if (a > b) swap(a, b);

        vector<int> v, v2;

        for (i = 1; d * i <= max(a, b); i++) v.push_back(d * i);

        for (i = 1; i <= d; i++) if (i % d == 0) v2.push_back(i);

        int ans = 0;

        for (i = 0; i < v.size(); i++) for (j = 0; j < v2.size(); j++) if (gcd(v[i], v[j]) == d) {
            printf("%d %d\n", d, v[i]);
            if (i != d && i < min(a, b)) {
                ans += 2;
            } else {
                ans += 1;
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
