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

const int MAXN = 107;
int N, d[MAXN], used[MAXN];

int in(void) { int x; scanf("%d", &x); return x; }

int check(int a, int b) {
    int sum = 0, carry = -1;

    while (a > 0 && b > 0) {
        int a_digit = a > 0 ? a % 10, a / 10 : -1;
        int b_digit = b > 0 ? b % 10, b / 10 : -1;

        if (a == -1) a = 0;
        if (b == -1) b = 0;

        if (a + b == 0) return true;
    }

    return false;
}

int func(int x) {
    int ans = 1;

    memset(used, 0, sizeof(used));

    used[x] = 1;



    return 1;
}

int main(void) {
    N = in();

    int i;

    for (i = 0; i < N; i++) d[i] = in();

    sort (d, d + N);

    if (d[0] == 0)  ans += 1;
    if (d[N-1] == 100) ans += 1;



    return 0;
}
