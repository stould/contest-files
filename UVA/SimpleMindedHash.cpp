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

int L, S, T = 1, dp[30][30][400];

int rec(int last, int len, int sum) {
    if(sum > S || len > 26) return 0;

    if(len == L) return sum == S ? 1 : 0;

    if(dp[last][len][sum] != -1) return dp[last][len][sum];

    int curr = 0;

    for(int i = last + 1; i <= 26; i++) {
        curr += rec(i, len + 1, sum + i);
    }
    return dp[last][len][sum] = curr;
}

int main(void) {
    freopen("i.in", "r", stdin);

    while(scanf("%d%d", &L, &S) == 2 && !(L+S == 0)) {
        memset(dp, -1, sizeof(dp));
        if(L > 26 || S > 351) {
            printf("Case %d: %d\n", T++, 0);
        } else {
            printf("Case %d: %d\n", T++, rec(0, 0, 0));
        }
    }
    return 0;
}
