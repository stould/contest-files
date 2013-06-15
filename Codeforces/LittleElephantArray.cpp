#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

int n, m, v[100000], dp[100000][100000];

int main(void) {
    scanf("%d%d", &n, &m);
    memset(dp, 0, sizeof(dp));
    REP(i, n) {
        scanf("%d", &v[i]);
        if(i > 0) dp[i] += dp[i - 1];
        if(v[i] == m) {
            dp[i] += 1;
        }
    }

    else puts("NO");
    return 0;
}



