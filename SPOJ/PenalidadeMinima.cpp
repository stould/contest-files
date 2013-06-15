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

const int MAXN = 1010;
const int MOD = 1000000;
int N, v[MAXN][MAXN], dp[MAXN][MAXN];

int cost(int a, int b) {
    ll tmp = (ll) a * b;
    int ans = 0;
    while(tmp % 10 == 0) {
        ans += 1;
        tmp /= 10LL;
    }
    return ans;
}

int main(void) {
    scanf("%d", &N);
    REP(i, N) REP(j, N) scanf("%d", &v[i][j]);

    REP(i, N) REP(j, N) {
        if(j - 1 >= 0) {
            dp[i][j] = min()
        }

    }

    return 0;
}


