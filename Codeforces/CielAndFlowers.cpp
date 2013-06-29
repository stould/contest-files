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

typedef long long Int;
typedef unsigned uint;

int R, G, B;

Int func(int R, int G, int B) {
    Int ans = 0LL;

    int i;

    for (i = 0; i < 3; i++) {
        int n_r = R - i;
        int n_g = G - i;
        int n_b = B - i;

        if (n_r < 0 || n_g < 0 || n_b < 0) continue;

        ans = max(ans, (Int) i + (n_r / 3 + n_g / 3 + n_b / 3));
    }

    return ans;
}

int main(void) {
    scanf("%d%d%d", &R, &G, &B);

    printf("%I64d\n", func(R, G, B));

    return 0;
}
