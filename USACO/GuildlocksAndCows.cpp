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

const int MAXN = 20020;

int N, X, Y, Z;

pair<int, int> p[MAXN];

int naive(void) {
    int i;
    int j;
    int ans = 0;

    for (i = 0; i <= 1000; i++) {
        int pr = 0;
        for (j = 0; j < N; j++) {
            if (i < p[j].first) pr += X;
            else if (i > p[j].second) pr += Z;
            else pr += Y;
        }
        chmax(ans, pr);
    }

    return ans;
}

/*
    bounds are such high, submitting a naive solution until got an idea for bigger test cases
*/

int main(void) {
    freopen("milktemp.in", "r", stdin);
    freopen("milktemp.out", "w", stdout);
    N = in();
    X = in();
    Y = in();
    Z = in();

    int i;

    for (i = 0; i < N; i++) {
        p[i].first = in();
        p[i].second = in();
    }

    int ans = naive();

    printf("%d\n", ans);

    return 0;
}
