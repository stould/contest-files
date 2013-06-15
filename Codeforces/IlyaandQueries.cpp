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

const int MAXN = 100009;
char str[MAXN];
int N, Q, dp[MAXN];

int main(void) {
    int i, l, r;

    scanf("%s%d", str, &Q); N = strlen(str);

    if (str[0] == str[1]) {
        dp[0] = 1;
    } else {
        dp[0] = 0;
    }

    for (i = 1; i < N - 1; i++) {
        dp[i] = dp[i - 1];
        dp[i] += str[i] == str[i + 1];
    }
    dp[N-1] = dp[N-2];

    for ( ; Q--; ) {
        scanf("%d%d", &l, &r); l -= 1; r -= 1;
        if (l == r) {
            if (r == N - 1) {
                printf("0\n");
            } else {
                printf("%d\n", str[l] == str[l + 1]);
            }
        } else {
            if (l > 0) {
                printf("%d\n", dp[r-1] - dp[l-1]);
            } else {
                printf("%d\n", dp[r-1]);
            }
        }
    }

    return 0;
}
