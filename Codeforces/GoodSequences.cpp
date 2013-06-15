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

const int MAXN = (int) 10e5;
int N, ans = 1, v[MAXN+10], ok[MAXN+10] = {0}, dp[MAXN+10] = {0}, gotcha = 0;
vector<int> rem[MAXN+10];

int main(void) {
    scanf("%d", &N);
    REP(i, N) {
        scanf("%d", &v[i]);
        ok[v[i]] = 1;
        gotcha = max(gotcha, v[i]);
    }
    gotcha += 5;
    FOR(i, 2, gotcha+1) for(int j = i; j <= gotcha; j += i) {
        rem[j].push_back(i);
    }
    REP(i, gotcha+1) if(ok[i] == 1) {
        int now = 1;
        REP(j, rem[i].size()) {
            now = max(now, dp[rem[i][j]] + 1);
        }
        ans = max(ans, now);
        REP(j, rem[i].size()) {
            dp[rem[i][j]] = max(dp[rem[i][j]], now);
        }
    }
    printf("%d\n", ans);
    return 0;
}
