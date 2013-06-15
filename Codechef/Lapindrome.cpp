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

int in(void) { int x; scanf("%d", &x); return x; }

int T, N;
char str[1010];

int main(void) {
    T = in();

    for ( ; T--; ) {
        scanf("%s", str); N = strlen(str);

        string r, l;

        int mid = (int) N / 2;

        r = string(str, str + mid);

        if (N % 2 == 0) {
            l = string(str + mid, str + (2 * mid));
        } else {
            l = string(str + mid + 1, str + (2 * mid + 1));
        }
        sort(r.begin(), r.end()); sort(l.begin(), l.end());

        if (r == l) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
